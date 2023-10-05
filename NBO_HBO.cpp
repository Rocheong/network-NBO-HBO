#include <stdio.h>
#include <stdint.h>

int main(void){
	uint32_t little=0x00000000;//4바이트  바이너리를 받기 위한 변수 
	uint32_t a[4];//4바이트 배열 
	uint32_t str[1];//파일을 읽고 저장할 변수 
	FILE *rp;//파일포인터 
	rp=fopen(".\\파일1.bin","rb");//파일1을 rb형식으로 연다 
	fread(str, sizeof(char)*4, 1, rp);//파일을 읽고 4바이트씩 1번 받아와서 str에 저장 
	fclose(rp);//파일 닫기 
	for(int i=0;i<4;i++){//반복문 
		a[i]=str[0];//str을 a[i]에 넣는다. 
	}
	a[0] = (a[0] & 0xff000000)>>24;//&연산자로 필요없는 부분을 0으로 만든 후 엔디언 변환 
	a[1] = (a[1] & 0x00ff0000)>>8; //&연산자로 필요없는 부분을 0으로 만든 후 엔디언 변환 
	a[2] = (a[2] & 0x0000ff00)<<8; //&연산자로 필요없는 부분을 0으로 만든 후 엔디언 변환 
	a[3] = (a[3] & 0x000000ff)<<24;//&연산자로 필요없는 부분을 0으로 만든 후 엔디언 변환 
	for(int i=0;i<4;i++){//반복문 
		little+=a[i]; //리틀에 모두 더한다. 
	}
	FILE *wp;//파일포인터 
	wp=fopen(".\\파일2.bin","wb");//파일을 쓰기모드로 연다 
	fwrite(&little,sizeof(char)*4,1,wp);//파일에 리틀에 저장된 것을 4바이트씩 1번 넣는다. 
	fclose(wp);//파일 닫기 
}
