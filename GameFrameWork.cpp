#include"gameframework.h"

/*����100��ÿ��100����ˢ�����½����ͼ��*/
int interval = 100;//TODO: 1 ���ö�ʱ��ʱ��������λ���룩
// TODO: 1 ���ô���: ���� �߶�
int screenWidth = 600;
int screenHeight=600;
int stop = 0;//�Ƿ�ֹͣ��Ϸ
//-----------------------------------//
int times = 0; 
/*��ʼ����Ϸ */
void initgame()
{
	srand((unsigned)time(NULL));//�������ʼ��
	setbkcolor(NULL);//����ɫ
	setbkmode(TRANSPARENT);// ���ñ������ģʽ: TRANSPARENTΪ͸��
	gameInit();
}
/*
	�����ͼ��ʾ����
*/
 

/*������ʾ��Ϸ����*/
void paint()
{
	BeginBatchDraw();//��˫����
	cleardevice();// ����
	 
	gamePaint();
	//-----------------------------//
	EndBatchDraw();//�ر�˫����
}



/*��Ϸ����*/
void run()
{
	ExMessage msg ;
	//ExMessage key;
	while (1)	// ��Ϸ��ѭ��  �ɽ���break ����ѭ��
	{
		if (peekmessage(&msg,-1,true))
		{
			switch (msg.message)
			{
			case WM_MOUSEMOVE://����ƶ�
				gameMousemove(msg.x, msg.y);
				break;
			case WM_LBUTTONDOWN://�������
				gameMouseDown(msg.x, msg.y);
				break;
			case WM_LBUTTONUP://���̧��
				gameMouseUp(msg.x, msg.y);
				break;
			case WM_LBUTTONDBLCLK://���˫��
				 
				break;
			case WM_RBUTTONDOWN://�Ҽ�����
				 
				break;
			case WM_RBUTTONUP://�Ҽ�̧��
				gameMouseRightDown(msg.x, msg.y);
				break;
			case WM_RBUTTONDBLCLK://�Ҽ�˫��
				 
				break;
			case WM_KEYDOWN:
				gameKeypress(msg.vkcode);
				break;
			}
			paint();
			continue;
		}
		
		 
		//------ʱ�䴦�� ��-----------//
		Sleep(1);
		times++;
		if(times%(interval/10)!=0){
			continue;
		}
		times=0;
		if(stop)
		{
			break;
		}
		gameInterval();
		 
		//-------------------------------//
		paint();// ˢ����ʾ��Ϸ����
	}
}



/*����͸������ͼ*/
 void drawImage(int  picture_x, int picture_y,IMAGE* picture  ) //xΪ����ͼƬ��X���꣬yΪY����
{

	// ������ʼ��
	DWORD *dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD *draw = GetImageBuffer(); 
	DWORD *src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ��ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ��ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x )+ (iy +   picture_y ) * graphWidth; //���Դ������صĽǱ�
				if (dstX<0) continue;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
/*����ͼƬ͸����*/
void drawImageAlpha(int x0, int y0, IMAGE* img, double f)
{
	//���ͼƬ�ߴ�
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();


	//PͼΪ����ͼ,RSΪĿ��ͼƬ
	static IMAGE RS(qwidth, qheight);
	static IMAGE P(qwidth, qheight);


	//����ͼ�Ļ���
	getimage(&P, x0, y0, qwidth, qheight);


	//��ȡָ�룬��Ϊ͸���ȼ���
	DWORD* M = GetImageBuffer(&P);
	DWORD* N = GetImageBuffer(img);
	DWORD* R = GetImageBuffer(&RS);


	// ����������ͼģʽ�������˸����
	BeginBatchDraw();


	//�����븳ֵ
	int i, j;
	for (i = 0; i < qheight; i++) {
		for (j = 0; j < qwidth; j++) {
			int r, g, b;
			int ij;
			//����
			ij = i * qwidth + j;
			r = (int)((GetRValue(N[ij])) * (1 - f) + GetRValue(M[ij]) * f);
			g = (int)((GetGValue(N[ij])) * (1 - f) + GetGValue(M[ij]) * f);
			b = (int)((GetBValue(N[ij])) * (1 - f) + GetBValue(M[ij]) * f);
			R[ij] = RGB(r, g, b);
		}
	}


	//����ͼƬ���ͷ��ڴ�
	putimage(x0, y0, &RS);
	FlushBatchDraw();// ����
}
//������������Ƿ�����ײ
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 )
{
 return !(x1 + w1 < x2||
		 y1 + h1 < y2 ||
		 x2 + w2 <x1 ||
		 y2 + h2<y1 );
}
// ��������������Ϸ
int main  ()
{
	initgraph(screenWidth, screenHeight );		
	initgame();					// ��ʼ����Ϸ
	paint();// ˢ����ʾ��Ϸ����
	 
	flushmessage();		// �����껺����
	while (_kbhit()) _getch();	// ��ռ��̻�����
	run();						// ��ʼ��Ϸ
	closegraph();//�ر�ͼ�λ�
	return 0;
}
 

//--------------���ŵľ����� ����Ϊ���� ��רҵ ���------------------// 