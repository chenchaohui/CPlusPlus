#define _CRT_SECURE_NO_WARNINGS
#include <sys/types.h> //linux/unix包含基本数据类型的头文件size_t,time_t
#include <sys/stat.h>  //系统调用函数头文件
#include <fcntl.h>     //包含open函数
#include <stdarg.h>    //包含可变参数函数的头文件
#include <string.h>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "ItcastLog.h"

#define ITCAST_DEBUG_FILE_	"socketclient.log"
#define ITCAST_MAX_STRING_LEN 		10240

//Level类别

#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4

int  LogLevel[5] = {IC_NO_LOG_LEVEL, IC_DEBUG_LEVEL, IC_INFO_LEVEL, IC_WARNING_LEVEL, IC_ERROR_LEVEL};

//Level的名称
char ICLevelName[5][10] = {"NOLOG", "DEBUG", "INFO", "WARNING", "ERROR"};

static int ITCAST_Error_GetCurTime(char* strTime)
{
	struct tm*		tmTime = NULL;
	size_t			timeLen = 0;    //无符号整型数据类型
	time_t			tTime = 0;	    //有符号64位整数类型
	
	tTime = time(NULL);
	tmTime = localtime(&tTime);
	//timeLen = strftime(strTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(strTime, 33, "%Y.%m.%d %H:%M:%S", tmTime);     //该函数的返回值的类型是size_t,作用是格式化时间字符串
	
	return timeLen;//如果格式后字符串的长度小于33，则函数赋值的字符串的长度，否则返回0；
}

static int ITCAST_Error_OpenFile(int* pf)
{
	char	fileName[1024];
	
	memset(fileName, 0, sizeof(fileName));
#ifdef WIN32
	sprintf(fileName, "c:\\itcast\\%s",ITCAST_DEBUG_FILE_);
#else
	//sprintf(fileName, "%s/log/%s", getenv("HOME"), ITCAST_DEBUG_FILE_);
	sprintf(fileName, "c:\\itcast\\%s",ITCAST_DEBUG_FILE_);
#endif
    
    *pf = open(fileName, O_WRONLY|O_CREAT|O_APPEND, 0666);
    if(*pf < 0)
    {
        return -1;
    }
	return 0;
}

static void ITCAST_Error_Core(const char *file, int line, int level, int status, const char *fmt, va_list args)
{
    char str[ITCAST_MAX_STRING_LEN];
    int	 strLen = 0;
    char tmpStr[64];
    int	 tmpStrLen = 0;
    int  pf = 0;
    
    //初始化
    memset(str, 0, ITCAST_MAX_STRING_LEN);
    memset(tmpStr, 0, 64);
    
    //加入LOG时间
    tmpStrLen = ITCAST_Error_GetCurTime(tmpStr);
    tmpStrLen = sprintf(str, "[%s] ", tmpStr);                          //函数sprintf的返回值是打印的字符的个数
    strLen = tmpStrLen;

    //加入LOG等级
    tmpStrLen = sprintf(str+strLen, "[%s] ", ICLevelName[level]);
    strLen += tmpStrLen;
    
    //加入LOG状态
    if (status != 0) 
    {
        tmpStrLen = sprintf(str+strLen, "[ERRNO is %d] ", status);
    }
    else
    {
    	tmpStrLen = sprintf(str+strLen, "[SUCCESS] ");
    }
    strLen += tmpStrLen;

    //加入LOG信息
    tmpStrLen = vsprintf(str+strLen, fmt, args);
    strLen += tmpStrLen;

    //加入LOG发生文件
    tmpStrLen = sprintf(str+strLen, " [%s]", file);
    strLen += tmpStrLen;

    //加入LOG发生行数
    tmpStrLen = sprintf(str+strLen, " [%d]\n", line);
    strLen += tmpStrLen;
    
    //打开LOG文件
    if(ITCAST_Error_OpenFile(&pf))
	{
		return ;
	}
	
    //写入LOG文件
    write(pf, str, strLen);
    //IC_Log_Error_WriteFile(str);
    
    //关闭文件
    close(pf);
    
    return ;
}


void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...)
{
    va_list args;                      //va_list 等价于 char *
	
	//判断是否需要写LOG
//	if(level!=IC_DEBUG_LEVEL && level!=IC_INFO_LEVEL && level!=IC_WARNING_LEVEL && level!=IC_ERROR_LEVEL)
	if(level == IC_NO_LOG_LEVEL)
	{
		return ;
	}
	
	//调用核心的写LOG函数
    va_start(args, fmt);
    ITCAST_Error_Core(file, line, level, status, fmt, args);
    va_end(args);
    
    return ;
}
