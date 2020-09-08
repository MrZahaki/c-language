/*In the name of GOD*/
# nippy_hash
binary string to number && string to string && string to double && string to pointer && etc, format hash table, writed in C language .

@brief The binary hash table manager, It should be noted that there is no specific rule for the type of data stored in the code table and you can use any type of custom data. Note that it is up to the user to determine the type of data stored (based on the range of stored keys or other rules) 

# example:
    unsigned int cntr[4];
	  uint8_t  buffer[]="allah";
	  double data=1.00064;
	  for(cntr[0]='a';cntr[0]<'z';cntr[0]++)
        for(cntr[1]='a';cntr[1]<'z';cntr[1]++)
            for(cntr[2]='a';cntr[2]<'z';cntr[2]++)
                for(cntr[3]='a';cntr[3]<'z';cntr[3]++){
                        Hash_Add_STR_Double(buffer,data);
                        buffer[0]=cntr[0];
                        buffer[1]=cntr[1];
                        buffer[2]=cntr[2];
                        buffer[3]=cntr[3];
                        data = data+1.0005;
                }
    data=Hash_Read_Double("bacah");
    if((int)data!=Hash_Table_Fail)
          printf("\n out:%f",data);
Output: 
     
    size of code book: 5.859375 Mbyte
    out:15684.838640 /*bacah -> 15684.838640*/


# example:
    Hash_Add_STR_STR((uint8_t *)"Hello",(uint8_t *)"World");
    char *out=(char*)Hash_Read_STR_STR("Hello");
    
    if((char)out!=Hash_Table_Fail)
        printf("\n out: %s",out);
Output: 

    size of code book: 15 byte
    out: World /*Hello -> World*/

# example:
    void print_Hi(void){
      printf("%s","hello world");
    }

    int main()
    {
      void ( *func)(void);
      Hash_Add_STR_Code("my func", &print_Hi);
      func = Hash_Read_ADDRSS("my func") ;
      func();
      
      return 0;
    }
 Output:
 
      size of code book: 17 byte
      out: hello world /*my func -> function*/
      
