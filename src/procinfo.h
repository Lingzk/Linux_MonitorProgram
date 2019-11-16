
#include "findway.h"
#include "procnode.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <pwd.h>


using namespace std;


class CProcInfo{
private:
    vector<proc_node> proc_info;    //所有进程的信息都存在vector容器proc_info中
    int proc_number;                //系统中所有进程的数量
    int processor_number;           //本机中cpu的核心数
    double sys_cpu_rate;            //系统的CPU使用率
    double sys_mem_rate;            //系统的内存使用率
    unsigned long long total_mem;   //系统总共内存数量
    unsigned long long free_mem;    //系统使用的内存数量
    double sys_up_speed;            //系统上传网速(kb/s)
    double sys_down_speed;          //系统下载网速(kb/s)

public:
    CProcInfo();
    
    /*
     * 判断文件名是不是纯数字
     * @parameter:文件名
     * @return：是进程文件返回true，不是进程文件返回false
     */
    bool isNumber(char * file_name); 

    /*
     * 获取本系统中cpu的核心数
     * @return：核心数
     */
    int searchProcessor();

    /*
     * 获得当前的proc_node 并且通过temp返回
     * @parameter：用作返回值
     */
    void getCurProcNode(char * pid_path, proc_node * temp);

    /*
     * 获得当前的cpu总时间和idle，通过参数返回
     * @parameter：cpu总时间，idle时间
     */
    void getCurCpuTime(unsigned long long * cpu_time, unsigned long long * idle);

    /*
     * 获得系统的内存总量和当前使用量
     * @parameter：内存总量，当前空闲量，通过参数返回
     * @return：返回内存占用率
     */
    double getCurMemSize(unsigned long long * total_mem, unsigned long long * free_mem);

    /*
     * 获得当前收到的千字节和发送的字节
     * parameter：下载，上传
     */
    void getCurInterBytes(unsigned long long * receive_bytes,unsigned long long * transmit_bytes);

    /*
     * 搜寻dir_name目录下的所有进程，并将所有进程信息存在proc_number中
     * @return：搜寻成功返回ture，失败返回false
     */                
    bool searchProc();

    /*
     * 搜寻dir_name目录下的所有进程的占用信息
     * @return：搜寻成功返回ture，失败返回false
     */     
    bool searchSys();

    /*
     * 刷新所有进程的信息以及系统占用情况
     * @return：搜寻成功返回true，失败返回fase
     */
    bool flash();

    void show();
};
