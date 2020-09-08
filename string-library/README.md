# NiPpY_str
                                             /*DESIGNED BY NiPpY*/
					     	  MR ZAHAKI
						     V4
						     
__________________________________________________________________________________________________________________						     
 _MODE_ used in index_remover and Str_Extractor, StrCutter, index_adder, etc.
 
 Reset and Auto Mode:
 Auto mode or default mode, which is used to automatically manage external variables
 (memory continuity and loss avoidance).
 
 Insulate Mode:
 Insulate mode which is used to isolate the spaces allocated by this library
  
 Ex_0(StrCutter):
       char *st0,*st1
      _Mode_(_MODE_Auto)
      st0=StrCutter ("This is nippy string Library", 0, 19)
        Output: st0:"This is nippy string"
       st1=StrCutter(st0,5,12)
        Output: st0:"is nippy"    st1:"is nippy"
 
 Ex_0(StrCutter):
     char *st0,*st1
      _Mode_(_MODE_Insulate)
      st0=StrCutter ("This is nippy string Library", 0, 19)
       Output: st0:"This is nippy string"
      st1=StrCutter(st0,5,12)
       Output: st0:"This is nippy string"     st1:"is nippy"
	
	#define _MODE_Reset 1
	#define _MODE_Auto 1
	#define _MODE_Insulate 0
	
	void _MODE_(char M);
__________________________________________________________________________________________________________________

This function is used to measure length of the string:

eg.input="hello"

eg.output= 5

     int len(char *str_);

__________________________________________________________________________________________________________________

Used in StrSearch and FStrSearch methods for determine Search range in unit Byte 

    #define Search_Buffer_Size 120
__________________________________________________________________________________________________________________
search in the '_str'(reference) string for  find index of the '_search'(target) string.

mode StrSearch_All_Occurrences: finding all occurrences in text:

Eg__1  _str:Input  =  "Hello world! 2+2=4 ):"

   _search:Input="l"
		   
   Result:Output(integer array)  =  [4,3,4,10] fisrt eleman refere to len of the output array. 
   
   

Eg__2  _str:Input  =  "Hello world! 2+2=4 ):"

   _search:Input="ld!"
		   
   Result:Output(integer array)=[2,10] fisrt eleman refere to len of the output array.
   
   

Eg__3  _str:Input  =  "Hello world! 2+2=4 ):"

   _search:Input  =  "2"
		   
   Result:Output(integer array)  =  [3,14,16] fisrt eleman refere to len of the output array.
   
mode StrSearch_First/Next_Occurrence: finding first occurrence in text:

(integer return  type)

Eg__4   _str:Input="Hello world! 2+2=4 ):"

   _search:Input="o"
   
   Mode: StrSearch_First_Occurrence
   
   Result:Output(integer ) = 5 (index of searched string).
   
   
   search:Input="o"
   
   Mode: StrSearch_Next_Occurrence
   
   Result:Output(integer ) = 8 (index of searched string).

	#define StrSearch_All_Occurrences   0

	#define StrSearch_First_Occurrence   1 

	void* StrSearch(char* _str,char* _search ,char _mode );
 __________________________________________________________________________________________________________________

 this function is used to replace a word with another word in the desired string.
 
 Inputs:
   char* _str: Reference string to do the placement on it.
   
   char *Search_str: A word or sentence from the reference string that will be changed.
   
   char *Replace_str:  A word or sentence that will be placed in the Search_str location of the reference string.
   
   char _Mode: Mode of operation (see below)
  
  Mode 0:  StrReplace_All_Occurrences  
     finding and replacing all occurrences in text
     
   EX__1:  
         dest="the Microsoft Word is the word processor developed by Microsoft. It was first released on October 25, 1983."
         Search_str="Microsoft"
	 *
         Replace_str="NiPpY Str(:"
	 *
         _Mode:  StrReplace_All_Occurrences
	 *
         Result=StrReplace(dest, Search_str,Replace_str, _Mode)
	 *
         Result:(char *)="the NiPpY Str(: Word is the word processor developed by NiPpY Str(:. It was first released on 	October 25, 1983."
  
  Mode 1:  StrReplace_First/Next_Occurrence  
     finding first/next occurrence in text.
     
   EX__2:  
         dest="the Microsoft Word is the word processor developed by Microsoft. It was first released on October 25, 1983."
   Search_str="Microsoft"
   	*
         Replace_str="NiPpY Str(:"
	 *
         _Mode:  StrReplace_First_Occurrence
         *
	 Result=StrReplace(dest, Search_str,Replace_str, _Mode)
	 *
         Result:(char *)="the NiPpY Str(: Word is the word processor developed by Microsoft. It was first released on 		October 25, 1983."
	 
   Search_str="Microsoft"
   	*
        Replace_str="NiPpY"
	*
        _Mode:  StrReplace_Next_Occurrence
	*
         Result=StrReplace(dest, Search_str,Replace_str, _Mode)
	 *
         Result:(char *)="the NiPpY Str(: Word is the word processor developed by NiPpY. It was first released on October 	25, 1983."
 
 
	#define StrReplace_All_Occurrences   0
	#define StrReplace_First_Occurrence   1
	#define StrReplace_Next_Occurrence    2

	void *StrReplace(char *dest, char *Search_str,char *Replace_str, char _Mode);
 __________________________________________________________________________________________________________________
search in the string File(reference) for  find index of the _search(target) string. 

Eg__1  file name: st.txt content = "hello world helo he hel"

   _search:Input = "hel"
		   
   Result:Output(integer array) = [4,1,13,21] fisrt eleman refere to len of the output array.

Eg__2  file name: st.txt content = "hello world helo he hel"
   
   _search:Input = "o"
   
   Result:Output(integer array) = [4,5,8,16] fisrt eleman refere to len of the output array.


	int* FStrSearch(FILE *fp,char* _search);
 __________________________________________________________________________________________________________________

 convert number in string format to equivalent integer number.
 
 mode(state) = 0:decimal number in string format to decimal number.
 
 mode(state) = 1:HEX number in string format to decimal number.
 

eg__0 input = "23",mode(state)=0  output 23 (in integer format)

eg__1 input = "23",mode(state)=1  output 35

	 long int StrNumToInt(char *inp_,char state_);
 __________________________________________________________________________________________________________________ 

convert integer number to equivalent number in string format.

eg__0 input=233 output="233"

	 char *IntToStr(unsigned long int inp);
 __________________________________________________________________________________________________________________ 

convert float number to equivalent number in string format,with p parameter Determining the precision in the number of decimal places is possible.

-desined for signed and unsigned value

-note that max of 'precision'is nine.

eg__0 input = 833.328 p=8    output="833.32799999"

eg__1 input = -833.328 p=8    output="-833.32799999"

 	char *FloatToStr(long double Fl_Part,unsigned char p);
 __________________________________________________________________________________________________________________ 
cutting string from first index to last(desired) index.

-------------->support '_MODE_' function

eg__0  StrCutter("hello world ",3,7)    output = "lo wo"
	
	char *StrCutter(const char *_inp,int FIndex,int LIndex);
 __________________________________________________________________________________________________________________ 
This function checks whether the passed string is alphabetic or not, return 1 for true and 0 for false.

eg__0 IsAlphaStr("hello world ")    output=1(true)

	unsigned char IsAlphaStr(char *c);
 __________________________________________________________________________________________________________________ 	
COPY STR TO DEST0.

eg__0  StrCpy(a(string variable),"hello world ")    output('a' contents)="hello world "

	void StrCpy(char *_dest,const char *_st0);
 __________________________________________________________________________________________________________________ 
This function checks whether the passed single character is alphabetic or not, return 1 for true and 0 for false.

eg__0  IsAlpha(')')    output=0(false)

eg__1  IsAlpha('a')    output=1(true)

	unsigned char IsAlpha(int c);
 __________________________________________________________________________________________________________________ 
This function checks that if str1 (string format) is equal to str2 (string format) then
return 1(true mode) or 0(fsalse mode)

eg__0  StrComp(")" , ",")    output=0(false)

	unsigned char  StrComp(char *_st1, char *_st2);
 __________________________________________________________________________________________________________________ 
Str_IndexCreator used for create new string that save input data(_inp variable) and add new free indexes(Free space or special character that set by Fill character) any where in input data(_inp) (set by _index var).

the input processing is multi-stage and it can't be used simultaneously in several parts of the program
You must reset the function before using it at a time so that the interference of the information does not occur.



***index input must have even number elements
ex:[index_address,index Numbers]




step by step _index input:

input1=[index_address,index Numbers](integer)
input 1.1: first index address in primary string(_inp)(mode: Str_IndexCreator_ADD)
input 1.2: first Number of indexes you want to add them with default Fill value in specified address that set in input 2.

input2=[index_address,index Numbers](integer)
input 2.1:second index address in primary string(_inp)
input 2.2:second Number of indexes you want to add them with default Fill value in specified address that set in input 4.
.
.
.
input N+1;   and  set Mode variable to 'Str_IndexCreator_END' for start to extend String.
note that after using function set mode to 'Str_IndexCreator_Reset'





   Eg__1  _inp:"hello "
                   _index0 (unsigned int): {0,3}
                   function: Str_IndexCreator(_inp,0(Fill Not important),_index0,Str_IndexCreator_ADD);
                   Result: 1(successful to add)
**		   
		   _index1 (unsigned int): {5,2}
                   function: Str_IndexCreator(_inp,0(Fill Not important),_index1,Str_IndexCreator_ADD);
                   Result: 1(successful add)
**                   
		   _index3 (unsigned int): {20,2}
                   function: Str_IndexCreator(_inp,0(Fill Not important),_index3,Str_IndexCreator_ADD);
                   Result: 0(fail to add)(address is not true)
**                   
		   function: Str_IndexCreator(_inp,'.',0(dont care),Str_IndexCreator_END);
                   Result:  "...hello.. "




   Eg__2  _inp:"hello "
                    _index0 (unsigned int): {0,3}
                    function: Str_IndexCreator(_inp,0(Fill Not important),_index0,Str_IndexCreator_ADD);
                    Result: 1(successful to add)
**
                    function: Str_IndexCreator(_inp,'t',0(dont care),Str_IndexCreator_END);
                    Result:  "ttthello "
**
                    _index0 (unsigned int): {5,2}
                    function: Str_IndexCreator(_inp,0(Fill Not important),_index0,Str_IndexCreator_ADD);
                    Result: 1(successful to add)
**
                    function: Str_IndexCreator(_inp,'l',0(dont care),Str_IndexCreator_END);
                    Result:  "lllhelloll "




   Eg__3  _inp:"hello "
                    _index0 (unsigned int): {0,3}
                    function: Str_IndexCreator(_inp,0(Fill Not important),_index0,Str_IndexCreator_ADD);
                    Result: 1(successful to add)
**
                    function: Str_IndexCreator(_inp,'t',0(dont care),Str_IndexCreator_END);
                    Result:  "ttthello "
**
                    RESETstr_IndexCreator();
                    Result: 1(successful to RESET)
**
                    _index1 (unsigned int): {4,3}
                    function: Str_IndexCreator(_inp,0(Fill Not important),_index1,Str_IndexCreator_ADD);
                    Result: 1(successful to add)
**
                    function: Str_IndexCreator(_inp,'t',0(dont care),Str_IndexCreator_END);
                    Result:  "hellttto "


	
	
	#define RESETstr_IndexCreator()     Str_IndexCreator(0,0,0,Str_IndexCreator_Reset)
	#define Str_IndexCreator_END    0
	#define Str_IndexCreator_ADD    1
	#define Str_IndexCreator_Reset  2//only use when    PROCESS_Str_IndexCreator_SaveSpace is '1'

	void *Str_IndexCreator(char *_inp,char Fill,void *_index, unsigned char _Mode);

__________________________________________________________________________________________________________________
Str_IndexAdder used for Adding new Indexes into input string(_inp) as same as Str_IndexCreator But in this function, the input processing is single-stage and it can be used simultaneously in several parts of the program.


In the Str_IndexCreator function, memory loss is less than this function, but this function has a stronger Performance than Str_IndexCreator function, see below examples:


_index frame(unsigned int):[size of frame,index_address0,index Numbers0,index_address1,index Numbers1,...]
-------------->support '_MODE_' function



   Eg__1
                   char *st;
*
                   _inp="hello ";
                   _index1={3,0,2};
                   function:   st=Str_IndexAdder(_inp, 'z', _index1);
                   Result st(string*)= "zzhello "
**
                   _index1={3,0,2};
                   function:   st=Str_IndexAdder(st, 'Q', _index1);
                   Result st= "QQzzhello "
		   
		   
   Eg__2
*
                   _inp="hello ";
                   _index1={3,0,2};
                   function:   st=Str_IndexAdder(_inp, 'z', _index1);
                   Result st(string*)= "zzhello "
**
                    _inp=" world ";
                   _index1={7,5,2,0,3,1,1};
                   function:   st=Str_IndexAdder(_inp, 'z', _index1);
                   Result st(string*)= "QQQ QworlQQd "

	void *Str_IndexAdder(char *_inp,char Fill,unsigned int *_index);


__________________________________________________________________________________________________________________
Str_IndexRemover is used to delete a specified index of the string. see Examples:
Note that Index start form zero.

-------------->support '_MODE_' function


   Eg__1
                char *fp;
*
                _inp="hello world";
                _index=1;
                function: fp=Str_IndexRemover(_inp,1);
                result="hllo world"
**
                _index=5;
                function: fp=Str_IndexRemover(fp,5);
                result="hllo orld"

	void *Str_IndexRemover(char *_inp, unsigned int _index);
 ________________________________________________________________________________________________________________________

 Extracting string from first index to last(desired) index.
 
 ---> LIndex=0 means that Extract from 'Findex' to last index,you can also use 'ToEnd' directive .
 
  -------->support '_MODE_' function
	eg__0(mode: dont care) Str_Extractor("hello world",5,10)    output="hello"
	
 	#define ToEnd 0
 	void *Str_Extractor(char *_inp,unsigned int FIndex,unsigned int LIndex);
 _______________________________________________________________________________________________________________________
 
 * Inputs:
 
 * _st: input string
 * Mode:Mode of operation(input) or input character in Default Mode(see below).
 * Math_validate_FLG: *Address* used in Str_Parse_Math Mode. true mode=1, false mode=0(see below)(output).
 * function output: unsigned int two dimensional array.
 * Note that first element in output is number of array elements
 
Use this function to parse the string in the following modes:
  
  1-MathMode:
     This can be done in functions that analyze mathematical expressions or used in mathematical libraries.
     This function can verify the correctness of the mathematical discipline (at the introductory level) using the input      	   flag. (Developing) 
     
   EX__0:
           unsigned int **st
           char FLAG
           st=Str_Parse("2*pi p(3+2)-p%[32-3] ",Str_Parse_MathMode,&FLAG)
           output: FLAG: 0(validate false) | st={18,2,*,pi,p,(,3,+,2,),-,p,%,[,32,-,3,] }
  
  2-WordMode
     Use this to identify and find words in the input string.
  
   EX__2:
           unsigned int **st
           char FLAG(dont care),input[]="Microsoft Word is a word processor developed by Microsoft. It was first released on 		October 25, 1983 under the name Multi-Tool"
           st=Str_Parse(input,Str_Parse_WordMode,&FLAG)
           output: FLAG: (dont care) | st=	{20,Microsoft,Word,is,a,word,processor,developed,by,Microsoft,It,was,first,released,on,October,under,the,name,Multi-Tool }
	   
  3-DefaultMode
     Using this mode, you can select an arbitrary letter as the separator of the sentence.
     input character entered with MODE parameter
     
   EX__3:
           unsigned int **st
           char FLAG(dont care),input[]="Microsoft Word is a word processor developed by Microsoft. It was first released on 		October 25, 1983 under the name Multi-Tool"
           st=Str_Parse(input,Str_Parse_DefaultMode | 'd',&FLAG)
           output: FLAG: (dont care) | st={8,'Microsoft Wor',' is a wor',' processor ','evelope',' by Microsoft. It was 	   first release',' on October 25, 1983 un','er the name Multi-Tool'}
	   
	#define Str_Parse_MathMode 2
	#define Str_Parse_WordMode 1
	#define Str_Parse_DefaultMode 0
	
	void **Str_Parse(char *_st,char Mode,char *Math_validate_FLG/*1 true | 0 false*/)	   
 _______________________________________________________________________________________________________________________
 
  Use this function to join a string(_st0) to the beginning of another string(_dest).
  
   EX__0:
       char dest[10]="hello"
       StrCat(dest," world");
       out: dest="hello world"
 
	char *StrCat(char *_dest,const char *_st0);
 _______________________________________________________________________________________________________________________


  Use this function to join multiple strings(_st0,...,_stn) to the beginning of another string(_dest).
  
  n: The number of strings you want to add to the final string
  
  EX__0:
       char dest[20]="We Love"
       StrnCat(in,4," ","nippy"," ","string");
       out: dest="we love nippy string"
 
	char *StrnCat(char *_dest,int _n, ...);
