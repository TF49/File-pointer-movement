#include<stdio.h>
#define N 3
#define FILENAME "student.txt"
struct stuinfor{
	int id;//结点数据 
	char name[10];//姓名
	float score;//成绩 
}student[N],stu,*p;

int main()
{
	FILE *fp;
	p=student;
	int i;
	if((fp=fopen(FILENAME,"a+"))==NULL)
	{
		printf("文件打开失败！\n");
		return;
	}
	printf("请依次输入3个学生信息：\n");
	for(i=0;i<N;i=i+1,p=p+1)
	{
		scanf("%d %s %f",&p->id,p->name,&p->score);
	}
	//参数1为待存放数据的指针，2为每个数据块的大小，3为一共有多少记录，4为存放的文件的指针 
	fwrite(student,sizeof(struct stuinfor),N,fp); 
	//参数1为待移动的文件指针，2为偏移量（正数向后，负数向前，即移动一个stuinfor型位置），3为移动到的位置（当前为头）
	//参数3：SEEK_SET头可用0表示，SEEK_CUR为当前位置可用1表示，SEEK_END为尾可用2表示 
	fseek(fp,2*sizeof(struct stuinfor),SEEK_SET);
	//参数1为存放到的内存空间指针 
	fread(&stu,sizeof(struct stuinfor),1,fp);
	printf("第2个信息是：\n");
	printf("%d %s %f",stu.id,stu.name,stu.score);
	fclose(fp);
	return 0; 
 } 
