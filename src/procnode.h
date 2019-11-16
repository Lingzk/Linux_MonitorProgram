
//保存单个进程的详细信息
typedef struct proc_node{
    int pid;                    //进程号pid
    char cmd[16];               //进程命令
    char cmdline[256];          //进程详细命令，包含运行命令的参数等
    unsigned long long cpu_time;//此进程运行的总cpu时间，单看此参数无意义
    int uid;                    //进程所属用户的uid
    char username[64];          //进程所属用户的用户名
    int vsz;                    //虚拟消耗内存（KB）
    int rss;                    //实际使用物理内存（KB）
    char user[256];             //进程所属用户的用户名
    double proc_cpu_rate;        //CPU使用率
    double proc_mem_rate;        //内存使用率
}proc_node; 
