#include <stdio.h>
#include "myProject.h"
int main ()
{
	printf("Chief name is [jeonggaeul]\n");
	printMyName1();
	printMyName2();
	printMyName3();
	return 0;
}
/*자유롭게 수정가능 c파일 main이랑 같이 잘 돌아가는지 확인하고싶은사람은
    본인 함수빼고 다른함수를 주석처리한 후에 컴파일해서 돌려보기 makefile은 나중에 하기
<ex>1.c확인하고 싶은경우
int main ()
{
  printf("Chief name is gaeul\n");
	printMyName1();
	//printMyName2();
	//printMyName3();
	return 0;
} ->이렇게 한 후,  gcc main.c 1.c 실행해서 확인
*/
