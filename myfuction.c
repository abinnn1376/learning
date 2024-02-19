//全排列
void exc(int arry[],int sta,int end)
{
    int temp = arry[end];
    for(int i=end;i>=sta+1;i--)
    {
        arry[i] = arry[i-1];
    }
    arry[sta] = temp;
}

void exc_back(int arry[],int sta,int end)
{
     int temp = arry[sta];
     for(int i=sta;i<=end-1;i++)
     {
        arry[i] = arry[i+1];
     }
     arry[end] = temp;
}

void ins(int arry[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arry[i]);
    }
    printf("\n");
}


void asort(int arry[],int sta,int end)
{
    int i;
    if(sta == end)
    {
        ins(arry,end+1);
    }
    else
    {
        for(i=sta;i<=end;i++)
        {
            exc(arry,sta,i);
            asort(arry,sta+1,end);
            exc_back(arry,sta,i);
        }
    }
}


int main()
{
    int n,i,x,sta,end;
    scanf("%d",&n);
    sta = 0;
    end = n-1;
    int arry[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        arry[i] = x;
    }
    asort(arry,sta,end);
    
    return 0;
}



//素数
int Prime(int num) 
{
    if (num <= 1)
    {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            return 0;
        }
    }
    
    return 1;
}

//遍历数组
void prt(int a[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

//大小写
void AAA(char str[])
{
    int i;
    int len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if( str[i] <= 'z' && str[i] >= 'a')
        {
                str[i] = str[i] - 32;
        }
    }
}

//希尔排序
void ShellSort(int *arr, int size)  
{  
    int i, j, tmp, grp;  
    for (grp = size/ 2; grp > 0; grp /= 2) 
    {    
        for (i = grp; i < size; i++) 
        {  
            tmp = arr[i];  
            for (j = i - grp; j >= 0 && tmp < arr[j]; j -= grp)
            {  
                arr[j + grp] = arr[j];  
            }  
            arr[j + grp] = tmp;
        }  
    }  
}

//并查集
int init(int parent[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        parent[i] = -1;
    }
}

int f_root(int x,int parent[])
{
    int x_root = x;
    while(parent[x_root] != -1)
    {
        x_root = parent[x_root];
    }
    return x_root;
}

int uion(int x,int y,int parent[])
{
   int x_root = f_root(x,parent); 
   int y_root = f_root(y,parent);
   if(x_root == y_root)
   {
    return 0;
   }
   else
   {
    parent[x_root] = y_root;
    return 1;
   }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int parent[n],all[n-1][2];
    init(parent,n);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",all[i][j]);
        }
    }
    for(i=0;i<n-1;i++)
    {
        int x = all[i][0];
        int y = all[i][1];
        if(uion(x,y,parent)==0)
        {
            printf("ok");
            exit(0);  
        }
    }
     printf("no");
    
    return 0;
}

//斐波那契
int fbn(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
	{
		return fun(n-1)+fun(n-2);
	}
}