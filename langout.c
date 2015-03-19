#include <stdio.h>
#define MEM_SIZE 100000
char Memory[MEM_SIZE];
int Frame_Pointer;
int Stack_Pointer;
int Temp;
double Temp_F;
int main() { 
Frame_Pointer=0;
Stack_Pointer=0;
/*cDeclsNode*/
Stack_Pointer += 12;
/*cVarRefNode aa*/
(*(int*)(&Memory[(Frame_Pointer + 0)])) = 3;
/*cVarRefNode bb*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = 4;
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = /*cFuncCall factorial*/ 
factorial();
;
Temp = /*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)]));
printf("%d\n", Temp);
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = /*cFuncCall factorial*/ 
factorial();
;
Temp = /*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)]));
printf("%d\n", Temp);
Temp = /*cVarRefNode aa*/
(*(int*)(&Memory[(Frame_Pointer + 0)]));
printf("%d\n", Temp);
Temp = /*cVarRefNode bb*/
(*(int*)(&Memory[(Frame_Pointer + 4)]));
printf("%d\n", Temp);
Stack_Pointer -= 12;
  return 0;
}
int factorial() 
 {
/*cDeclsNode*/
/*cVarRefNode result*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = 1;
/*If/else block starting*/ 
if(/*cVarRefNode value*/
(*(int*)(&Memory[(Frame_Pointer + 0)]))) 
	goto LABEL_2;
goto LABEL_4;
/*Begin if(true) stmt*/ 
LABEL_2:
/*cDeclsNode*/
Stack_Pointer += 4;
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = /*cFuncCall factorial*/ 
factorial();
;
/*cVarRefNode result*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = (/*cVarRefNode value*/
(*(int*)(&Memory[(Frame_Pointer + 0)]))*/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)]))) ;
Stack_Pointer -= 4;
goto LABEL_4;
LABEL_4: ;
/*Done with if/else block*/ 

}
