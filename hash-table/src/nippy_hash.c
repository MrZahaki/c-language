/*In the name of GOD*/
#include "nippy_hash.h"



/* @breif this function adds string to string key in hash table
 * @param st_Key is an string format variable that will save into hash table.
 * @note the content of st_Key used as key to find st0 in code book
 *  - st_Key(key) -> st0(value)
 * @param st0 is an string format variable that will save into hash table.
 * @retval Hash_Status
 */
uint8_t Hash_Add_STR_STR(uint8_t *st_Key,uint8_t *st0){

return (uint8_t) Hash_Add_STR_Code( st_Key, STRIsolating((char *)st0));

}

/* @breif this function adds string to float key in hash table
 * @param st_Key is an string format variable that will save into hash table.
 * @note the content of st_Key used as key to find data in code book
 *  - st_Key(key) -> data(float value)
 * @param st0 is an string format variable that will save into hash table.
 * @retval Hash_Status
 */
uint8_t Hash_Add_STR_Double(uint8_t *st_Key, double data){
  double *data_buf = (double *)malloc(sizeof(double));
  *data_buf = data;
  return (uint8_t)Hash_Add_STR_Code( st_Key, data_buf);
}
//_____________________________________________________________________________________
//#define CODE_SIZE  5 byte :note number of bits is 5*8 - 1
//#define __MAX_CODE_SIZE	 CODE_SIZE+1

void *Hash_Table( uint8_t  *str, uint64_t  code, uint8_t _mode ){//mode of operation, string input,
static uint8_t   *Code_Book = NULL;
static uint64_t _Size = 0;
uint64_t str_cnt=0, _counter;//status_Flag


if( (_mode>>2 & 1) || (!_Size) ){
    if(Code_Book) free(Code_Book);/*Hash_Table_Destroy*/
    Code_Book =(uint8_t *) malloc(sizeof(uint8_t));
    _Size=0;
}

switch(_mode){
/*____________________________________________________________________________________________________--*/
case    Hash_Table_Add:
	_counter = Str_len((char *)str) + 1;

    if (code >32767/*MAX of 15 bit*/){ //39 bit code mode
        _Size+= CODE_SIZE;/*additional one byte for control code book protocol*/
        Code_Book =realloc(Code_Book, _Size/*code size + additional byte*/ + _counter/*string that we want to add in code book*/);

        /*buffer format : [code size status bit][code value][string key + 0]*/
		//*(Code_Book + _Size - __MAX_CODE_SIZE)=0;
		*(Code_Book + _Size - CODE_SIZE)=( ((code<<1)| 1/*24 bit mode*/) & 0xff ); //create designed buffer and place code value into it
		for(str_cnt = 1; str_cnt < CODE_SIZE; str_cnt++  )
			Code_Book[_Size-str_cnt] = ( ( (uint64_t)code >>  ( (CODE_SIZE-str_cnt) * 8 -1) ) & 0xff );//third section

    }
    else{   //15bit code
        _Size+=2;
        Code_Book =realloc(Code_Book, _Size/*code size + additional byte*/ + _counter/*string that we want to add in code book*/);
        //*(Code_Book+_Size-3)=0;
        *(Code_Book+_Size-2)=( (code<<1) & 0xff ); //create designed buffer and place code value into it
        *(Code_Book+_Size-1)=( (code >>7) & 0xff );//second section
    }

//second level: putting code into codebook


    _Size+=_counter;
    while( (Code_Book[_Size-(_counter--)] = *(str++))  );//PUTTING STRING INTO CODEBOOK
    //*(Code_Book+_Size)=0;
    //_Size--;

   // for(_counter=0;_counter<_Size;_counter++) printf( "%d %c %d \n",*(Code_Book+_counter), *(Code_Book+_counter), _counter );

    //printf( "size= %d \n",_Size );
	return (int *)0;
/*____________________________________________________________________________________________________--*/
case    Hash_Table_Check: //add new entry into Code Book  and check it for ensure that Entered code dont exist in CodeBook

  _MODE_(_MODE_Insulate);
	if( ( (int) Hash_Table( str, (uint64_t)0, Hash_Table_Read) != -1) || ((int)Hash_Table((uint8_t *)"", code, Hash_Table_Read)!= -1 ) )  return (int *)0;
  _MODE_(_MODE_Reset);

	break;

/*____________________________________________________________________________________________________--*/
case    Hash_Table_Read: //for reading code value enter string and put zero into code argument
                                //for reading  string from  equivalent code value put zero into string argument
        //_len=Str_len(str);

/*----*/if(!(code)){//read code value (input : string) (function output: code number ,unsigned long int) (false mode return -1)
            if(_Size <3) return (int *)-1;/*EOF*/

            for( _counter=0; _counter<_Size; _counter++){
                //_mode=0;
                if(*(Code_Book+_counter) & 1){//number of bits > 15 bit mode

					_counter += CODE_SIZE;//_counter is address offset of string in current frame.
                    /*we use _counter variable  Temporary for indicate size of string in current frame of code book*/

                     if( StrComp( (char *)str,(char *)(Code_Book+_counter)) ){
                        code =  (Code_Book[_counter-CODE_SIZE] >> 1) & 0xff;

                        for( str_cnt = (CODE_SIZE - 1); str_cnt > 0; str_cnt--)
                            code |= ( ( (uint64_t)Code_Book[_counter-str_cnt] <<  ( (CODE_SIZE-str_cnt) * 8 -1) )  );//setting  count from first element to last
                        return (uint64_t *)code;

                     }//if

                     _counter += Str_len( (char *)(Code_Book+_counter) );


                }//if 23 bit mode

                else{//15bit mode
                    _counter += 2;//_counter is address offset of string in current frame.
                    /*we use _counter variable  Temporary for indicate size of string in current frame of code book*/

                     if( StrComp( (char *)str,(char *)(Code_Book+_counter)) ){

                        code = ( (Code_Book[_counter - 2] >> 1) & 0xff) | ( ( Code_Book[_counter - 1] << 7 ) & 0xff00 );
                        return (uint64_t *)code;

                     }//if

                     _counter += Str_len( (char *)(Code_Book+_counter) );


                }//else 15 bit mode
            }//for
        }//read code value if-->code

/*----*/else{//read string value(input: code) (function output: string) (false mode return NULL)
                if(_Size <3) return (int *)-1;/*EOF*/
                static uint8_t *Out_Str = 0;
                uint64_t tmp_buffer;

                if(Out_Str) free(Out_Str);

            for( _counter=0; _counter < _Size;  ){

                if( Code_Book[_counter] & 1){//number of bits > 15 bit mode
                    _counter += CODE_SIZE;

                    //we are getting code from code book
                    tmp_buffer =  (Code_Book[_counter-CODE_SIZE] >> 1) & 0xff;
                    for( str_cnt = (CODE_SIZE - 1); str_cnt > 0; str_cnt--)
                        tmp_buffer |= ( (uint64_t)Code_Book[_counter-str_cnt] <<  ( (CODE_SIZE-str_cnt) * 8 -1) ) ;//setting  count from first element to last
                        //tmpbuf = ( (CODE_SIZE-str_cnt) * 8 -1) ;

                    //_len = Str_len( (char *)(Code_Book+_counter) );

                    if( code == tmp_buffer )
                        return  (uint8_t *)STRIsolating( (char *)(Code_Book+_counter) );

                    while(*(Code_Book+_counter++));
                            //printf("_counter= %d\n",_counter);

                }//if(*(Code_Book+_counter) & 1)
                else{//15 bit mode
                    _counter += 2;

                    if( (uint16_t)code == (uint16_t)( (uint8_t)( Code_Book[_counter-2]>>1) | (uint16_t )( Code_Book[_counter-1] << 7 ) ) ){
                        //while(*(Code_Book+_counter+_len))    _len++;
                        return  (uint8_t *)STRIsolating( (char *)(Code_Book+_counter) );



                    }//if
                    while(*(Code_Book+_counter++));
                    //printf("_counter= %d\n",_counter);

                }//else
            }//for(_counter=0;_counter<_Size;)
        }//big else
		break;
}//switch
return (int *)-1;
}//func




/*End with the name of GOD*/
