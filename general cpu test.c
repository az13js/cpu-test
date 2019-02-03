/*
 * �˴������ڲ��� CPU ����������
 * �÷���ֱ�����г��򼴿ɡ�
 */
#include <stdio.h>
#include <time.h>
#include <malloc.h>

int test(const unsigned char *buf, int bufsize){
	unsigned int res;
	int i;
	for (i = 0, res = 0; i < bufsize; i++){
		res += buf[i];
	}
	return (int)res;
}

int main(int argv, char **argc){
	FILE *fp;
	clock_t start, end;
	int i, j, bufsize, count, res;
	float r, max;
	unsigned char *buf;
	r = 0.0;
	max = 0.0;
	count = 4000; /* һ���������ڵĲ��Դ��� */
	bufsize = 1024 * 1024;
	buf = (unsigned char *)malloc(bufsize * sizeof(char));
	if (NULL == (fp = fopen("test.dat", "rb"))){
		printf("Open test.dat fail.\n");
		free(buf);
		return 0;
	}
	i = (int)fread(buf, 1, bufsize, fp);
	fclose(fp);
	if (i != bufsize){
		printf("Read != bufsize.\n");
		free(buf);
		return 0;
	}
	printf("�����������У���ر���������ȴ������\n");
	for(j = 0; j < 10; j++){
		printf("No%d:\n", j + 1);
		start = clock();
		for (i = 0; i < count; i++){
			res = test(buf, bufsize);
		}
		end = clock();
		r = (float)((double)count / (double)difftime(end, start));
		if (r > max){
			max = r;
		}
		printf("RES = %d\nѭ������ %d\n��ʱ�� %.0f ����\nƽ�� %.6f ��/���룬��� %.6f �� / ����\n\n", res, count, (float)difftime(end, start), r, max);
	}
	free(buf);
	return 0;
}
