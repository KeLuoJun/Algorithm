#include <stdio.h>
int main()
{
    int m,n,i;
    scanf("%d",&m);   //������ҩ��
    scanf("%d",&n);	   //����ȡҩ����
    
    int num[n];    
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);   //ÿ������ϣ��ȡ�ߵ�ҩƷ��
    }
    
    int count=0;
    for(i=1;i<=n;i++){
        if(num[i]<=m)
            m=m-num[i];
        else
            count++;
    }
    
    printf("%d\n",count);
    return 0;
}
