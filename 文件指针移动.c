#include<stdio.h>
#define N 3
#define FILENAME "student.txt"
struct stuinfor{
	int id;//������� 
	char name[10];//����
	float score;//�ɼ� 
}student[N],stu,*p;

int main()
{
	FILE *fp;
	p=student;
	int i;
	if((fp=fopen(FILENAME,"a+"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	printf("����������3��ѧ����Ϣ��\n");
	for(i=0;i<N;i=i+1,p=p+1)
	{
		scanf("%d %s %f",&p->id,p->name,&p->score);
	}
	//����1Ϊ��������ݵ�ָ�룬2Ϊÿ�����ݿ�Ĵ�С��3Ϊһ���ж��ټ�¼��4Ϊ��ŵ��ļ���ָ�� 
	fwrite(student,sizeof(struct stuinfor),N,fp); 
	//����1Ϊ���ƶ����ļ�ָ�룬2Ϊƫ������������󣬸�����ǰ�����ƶ�һ��stuinfor��λ�ã���3Ϊ�ƶ�����λ�ã���ǰΪͷ��
	//����3��SEEK_SETͷ����0��ʾ��SEEK_CURΪ��ǰλ�ÿ���1��ʾ��SEEK_ENDΪβ����2��ʾ 
	fseek(fp,2*sizeof(struct stuinfor),SEEK_SET);
	//����1Ϊ��ŵ����ڴ�ռ�ָ�� 
	fread(&stu,sizeof(struct stuinfor),1,fp);
	printf("��2����Ϣ�ǣ�\n");
	printf("%d %s %f",stu.id,stu.name,stu.score);
	fclose(fp);
	return 0; 
 } 
