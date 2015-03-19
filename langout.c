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
int factorial() 
 {
/*cDeclsNode*/
/*cVarRefNode result*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = 1;
if(/*cVarRefNode value*/
(*(int*)(&Memory[(Frame_Pointer + 0)]))) 
{
/*cDeclsNode*/
Stack_Pointer += 4;
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = factorial();
;
/*cVarRefNode result*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = (/*cVarRefNode value*/
(*(int*)(&Memory[(Frame_Pointer + 0)]))*/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)]))) ;
Stack_Pointer -= 4;
}

}
Stack_Pointer += 12;
/*cVarRefNode aa*/
(*(int*)(&Memory[(Frame_Pointer + 0)])) = 3;
/*cVarRefNode bb*/
(*(int*)(&Memory[(Frame_Pointer + 4)])) = 4;
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = factorial();
;
Temp = /*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)]));
printf("%d\n", Temp);
/*cVarRefNode temp*/
(*(int*)(&Memory[(Frame_Pointer + 8)])) = factorial();
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
