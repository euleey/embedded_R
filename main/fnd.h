#ifndef __FND_DRV_H__
#define __FND_DRV_H__
#define MAX_FND_NUM 6
#define FND_DATA_BUFF_LEN (MAX_FND_NUM + 2)
#define FND_DRIVER_NAME "/dev/perifnd"
#define MODE_STATIC_DIS 0
#define MODE_TIME_DIS 1
#define MODE_COUNT_DIS 2

int fndDisp(int num,int dotflag);
typedef struct FNDWriteDataForm_tag
{
	char DataNumeric[FND_DATA_BUFF_LEN];//숫자0-9
	char DataDot[FND_DATA_BUFF_LEN];//숫자0or1
	char DataValid[FND_DATA_BUFF_LEN];//숫자0or1
}stFndWriteForm,*pStFndWriteForm;

#endif// __FND_DRV_H__
