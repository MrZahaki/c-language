/*in the name of god*/
#ifndef NIPPY_HASH_H__
#define NIPPY_HASH_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "nippy_str.h"


#define Hash_Table_Add        0 //add new entry into Code Book(using str,code parameters)
#define Hash_Table_Check  8 //this mode check Entered code or string to ensure that Entered value exist in CodeBook.
#define Hash_Table_Read 1 //reading step by step buffer
#define Hash_Table_Destroy    4//destroy current Code Book

#define CODE_SIZE  9 /*default 9 byte: it is control Occupied space by code book between 3 to inifinity (: */

#define Hash_Table_StrNULL  (uint8_t *)""
#define Hash_Table_CodeNULL  0

/*@brief Hash_Status */
#define Hash_Table_Fail   -1
#define Hash_Table_OK   0

/*
@brief The binary hash table manager.
@param _mode is mode of operation
@note _modes:
-		Hash_Table_Add : add new entry into Code Book(using str,code parameters)
-	 	Hash_Table_Read : include 2 mode"read code [put zero into code variable and enter string]or read string[just enter code]") :reading step by step buffer
-		Hash_Table_Destroy : destroy current Code Book
-		Hash_Table_Check : add new entry into Code Book  and check it for ensure that Entered code dont exist in CodeBook
@param code is saved into hash table
@param str is saved into hash table
@note every str has its own code and code start from 1 to ( 2^(CODE_SIZE * 8) - 1 ).
@note the code value can be a pointer to function or string or any type value, you must be care about CODE_SIZE value

@note CodeBook Frame:
-		[Frame Code0, string0,[0],STR 1,[0],STR 2,[0]...]
-		frame code: [zero bit,bit1 set 16 bit mode(0) OR 32 bit mode(1) for code size ,bit2,...,bit15,.....,bit 23,..(data)]
-		zero in result, Always refer to false.

@retval is an unsigned long int number or status( Hash_Table_Fail **muust be checked** ).

*/
extern void *Hash_Table( uint8_t  *str, uint64_t  code, uint8_t _mode );


/* @breif this macro adds string and integral code in hash table.
 * @param str is an string format variable that will save into hash table.
 * @param code is an variable that will save into hash table.
 * @note In this case we can use two inputs simultaneously as hash keys
 * -  str <---> code
 * @retval Hash_Status
 */
#define Hash_Add_STR_Code(str,code)  (uint8_t*)Hash_Table( (uint8_t *)str, (uint64_t)code, Hash_Table_Add )


/* @breif this function adds string to float key in hash table
 * @param st_Key is an string format variable that will save into hash table.
 * @note the content of st_Key used as key to find data in code book
 *  - st_Key(key) -> data(float value)
 * @param data is an double format variable that will save into hash table.
 * @retval Hash_Status
 */
extern uint8_t Hash_Add_STR_Double(uint8_t *st_Key, double data);

/* @breif this function adds string to string key in hash table
 * @param st_Key is an string format variable that will save into hash table.
 * @note the content of st_Key used as key to find st0 in code book
 *  - st_Key(key) -> st0(value)
 * @param st0 is an string format variable that will save into hash table.
 * @retval Hash_Status
 */
extern uint8_t Hash_Add_STR_STR(uint8_t *st_Key,uint8_t *st0);

/* @breif this macro adds string  to pointer key  in hash table
 * @param st_Key is an string format variable that will save into hash table.
 * @note the content of st_Key used as key to find ptr pointer in code book
 *  - st_Key(key) -> ptr(location)
 * @param ptr is an pointer to any type format that will save into hash table.
 * @retval Hash_Status
 */
#define Hash_Add_STR_PTR(st_Key, ptr)  (uint8_t*)Hash_Add_STR_Code( st_Key,ptr)

/* @breif this macro used to read hash table by string key
 * @param st_Key is the string key that saved in hash table
 * @retval string content saved in code book block by using string key(means addrss)
 */
#define  Hash_Read_STR_STR(st_Key) (uint8_t *)Hash_Table((uint8_t *)st_Key,(uint64_t)0,Hash_Table_Read)


/* @breif this macro used to read hash table by using address(address is saved code in hash table)
 * @param addrss is the code saved in hash table
 * @retval string content saved in code book block by using code value(means addrss)
 */
#define  Hash_Read_STR(addrss) (uint8_t *)Hash_Table((uint8_t *)"",(uint64_t)addrss,Hash_Table_Read)

/* @breif this macro used to read hash table by string key
 * @param st_Key is the string key that saved in hash table
 * @retval address or code value saved in code book block by using string key(means addrss)
 */
#define  Hash_Read_ADDRSS(st_Key) (uint64_t *)Hash_Table((uint8_t *)st_Key,(uint64_t)0,Hash_Table_Read)

/* @breif this macro used to read hash table by string key
 * @param st_Key is the string key that saved in hash table
 * @retval float value saved in code book block by using string key(means addrss)
 */
#define  Hash_Read_Double(st_Key) *((double *) Hash_Table((uint8_t *)st_Key,(uint64_t)0,Hash_Table_Read) )


/* @breif This macro is used to check for the address entered to ensure that exists in the codebook.
 * @param st_Key is the string key that we want to check.
 * @retval Hash_Status **Hash_Table_OK means that the corresponding address is in the codebook **
 */
#define  Hash_Check_ADDRSS(addrss) (uint8_t *)Hash_Table((uint8_t *)"",(uint64_t)addrss,Hash_Table_Check)


/* @breif This macro is used to check for the entered string to ensure that exists in the codebook.
 * @param st_Key is the string key that we want to check.
 * @retval Hash_Status **Hash_Table_OK means that the corresponding key is in the codebook **
 */
#define  Hash_Check_STR(st_Key) (uint8_t *)Hash_Table((uint8_t *)st_Key,(uint64_t)0,Hash_Table_Check)




#endif
/*end with the name of god*/
