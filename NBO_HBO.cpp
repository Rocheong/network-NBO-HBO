#include <stdio.h>
#include <stdint.h>

int main(void){
	uint32_t little=0x00000000;//4����Ʈ  ���̳ʸ��� �ޱ� ���� ���� 
	uint32_t a[4];//4����Ʈ �迭 
	uint32_t str[1];//������ �а� ������ ���� 
	FILE *rp;//���������� 
	rp=fopen(".\\����1.bin","rb");//����1�� rb�������� ���� 
	fread(str, sizeof(char)*4, 1, rp);//������ �а� 4����Ʈ�� 1�� �޾ƿͼ� str�� ���� 
	fclose(rp);//���� �ݱ� 
	for(int i=0;i<4;i++){//�ݺ��� 
		a[i]=str[0];//str�� a[i]�� �ִ´�. 
	}
	a[0] = (a[0] & 0xff000000)>>24;//&�����ڷ� �ʿ���� �κ��� 0���� ���� �� ����� ��ȯ 
	a[1] = (a[1] & 0x00ff0000)>>8; //&�����ڷ� �ʿ���� �κ��� 0���� ���� �� ����� ��ȯ 
	a[2] = (a[2] & 0x0000ff00)<<8; //&�����ڷ� �ʿ���� �κ��� 0���� ���� �� ����� ��ȯ 
	a[3] = (a[3] & 0x000000ff)<<24;//&�����ڷ� �ʿ���� �κ��� 0���� ���� �� ����� ��ȯ 
	for(int i=0;i<4;i++){//�ݺ��� 
		little+=a[i]; //��Ʋ�� ��� ���Ѵ�. 
	}
	FILE *wp;//���������� 
	wp=fopen(".\\����2.bin","wb");//������ ������� ���� 
	fwrite(&little,4,1,wp);//���Ͽ� ��Ʋ�� ����� ���� 4����Ʈ�� 1�� �ִ´�. 
	fclose(wp);//���� �ݱ� 
}