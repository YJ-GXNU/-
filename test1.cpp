#include<iostream>
#include<math.h>
using namespace std;

//˳��ջ����
#define OK 1
#define ERROR 0
#define MAXSIZE  100
int syt=1;
typedef int Status;
typedef double SElemType;
typedef char CElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;


typedef struct{
	CElemType *base;
	CElemType *top;
	int stacksize;
}ChStack;



//����˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S)
{                                        // ����һ����ջ S 
	S.base = new SElemType[MAXSIZE];	 //Ϊ˳��ջ����һ���������ΪMAXSIZE������ռ�
	if(!S.base)
		exit (OVERFLOW);    	         //�洢����ʧ��
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//����˳��ջ����ջ
Status Push(SqStack &S,SElemType e)
{                                        // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base==S.stacksize)
		return ERROR;	                 //ջ��
	*(S.top++) = e;	                     //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//����˳��ջ�ĳ�ջ
Status Pop(SqStack &S,SElemType &e)
{                                        // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.base == S.top)
		return ERROR;                    //ջ��
	e = *(--S.top);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//ȡ����˳��ջ��ջ��Ԫ��
Status GetTop(SqStack S,SElemType &e)
{                                        // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top-1);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//����ջ��
Status StackEmpty(SqStack &S){
	if(S.top-S.base>0)return 1;          //ջ���շ���1
		else return 0;
}






//����˳��ջ�ĳ�ʼ��
Status InitStack(ChStack &H)
{                                        // ����һ����ջ H 
	H.base = new CElemType[MAXSIZE];	 //Ϊ˳��ջ����һ���������ΪMAXSIZE������ռ�
	if(!H.base)
		exit (OVERFLOW);    	         //�洢����ʧ��
	H.top = H.base;
	H.stacksize = MAXSIZE;
	return OK;
}
//����˳��ջ����ջ
Status Push(ChStack &H,CElemType e)
{                                        // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if(H.top-H.base==H.stacksize)
		return ERROR;	                 //ջ��
	*(H.top++) = e;	                     //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//����˳��ջ�ĳ�ջ
Status Pop(ChStack &H,CElemType &e)
{                                        // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(H.base == H.top)
		return ERROR;                    //ջ��
	e = *(--H.top);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//ȡ����˳��ջ��ջ��Ԫ��
Status GetTop(ChStack H,CElemType &e)
{                                        // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(H.top == H.base){
		e='0';
		return ERROR;
	}
	e = *(H.top-1);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//����ջ��
Status StackEmpty(ChStack &H){
	if(H.top-H.base>0)return 1;          //ջ���շ���1
		else return 0;
}


//����ջ��ֵ
float SetS(ChStack &SS,int &q){      
	ChStack X;                           
	InitStack(X);                        //Xջ�Ĺ������ʼ��
	double n=1,S=0;
	int m=0;
	char e;                              //�������ĸ���ֵ
	while(StackEmpty(SS)&&m==0){         
		Pop(SS,e);
		Push(X,e);                       //Sջ�ǿ�ʱ��ջ��Xջ
		if(e=='.'){                      //����С��ʱ�ļ���
			n=n/10;
			Pop(X,e);
			while(StackEmpty(X)){
				Pop(X,e);
				switch(e){
					case '0':S=S+0;break;
		            case '1':S=S+1*n;break;
		            case '2':S=S+2*n;break;
	          	    case '3':S=S+3*n;break;
	                case '4':S=S+4*n;break;
	                case '5':S=S+5*n;break;
	                case '6':S=S+6*n;break;
	                case '7':S=S+7*n;break;
                    case '8':S=S+8*n;break;
                    case '9':S=S+9*n;break;
	          	    default:break;
				}
	        	n=n/10;
			}
			n=1;m=1;
		}
	}
	while(StackEmpty(X)){
		Pop(X,e);
		Push(SS,e);
	}
	while(StackEmpty(SS)){
		Pop(SS,e);
		switch(e){
			case '0':S=S+0;break;
		    case '1':S=S+1*n;break;
		    case '2':S=S+2*n;break;
	  	    case '3':S=S+3*n;break;
	        case '4':S=S+4*n;break;
	        case '5':S=S+5*n;break;
	        case '6':S=S+6*n;break;
	        case '7':S=S+7*n;break;
            case '8':S=S+8*n;break;
            case '9':S=S+9*n;break;
		    default:break;
		}
		n=n*10;                            //�������ֵļ���
	}
	if(q==0){
		return S;                          
	}
	else if(q==1){
		q=0;
		return -S;                         //��ֵ�������ж�
	}
}


//�����ż��㺯��
void count(SqStack &S,ChStack &H){
	double a,b,c;
	double pi=3.14192653589793;
	char x;
	Pop(S,b);
	Pop(H,x);                              //������ֵ
    switch(x){
	    case '+':
		case '-':
			if(StackEmpty(S)){
				Pop(S,a);
				c=a+b;break;
			}else syt=ERROR;
		case '*':
			if(StackEmpty(S)){
				Pop(S,a);
				c=a*b;break;
			}else syt=ERROR;
		case '/':
			if(StackEmpty(S)){
				Pop(S,a);
				c=a/b;break;
			}else syt=ERROR;
		case 'c':
			b=b/180*pi;c=cos(b);break;
		case 'a':
			b=b/180*pi;c=atan(b);break;
		case 's':
			b=b/180*pi;c=sin(b);break;
		case 't':
			b=b/180*pi;c=tan(b);break;
		case 'i':
			b=b/180*pi;c=asin(b);break;
		case 'o':
			b=b/180*pi;c=acos(b);break;
		default:break;                     //��ͬ���Ž��в�ͬ���㣨���ڽ���ֵ�洢Ϊ�����ŵģ����ԡ�-��ͬ�Լӷ����㣩
	}
	Push(S,c);                             //���������Sջ
}


//���Ǻ�������
/*void trigonometric(ChStack &SS,SqStack &S,CElemType ch,int &q){
	int k=0;
	char d=ch;
	double t,pi=3.14192653589793;
	ChStack D;
	InitStack(D);
	while(d!='('&&k==0){
		Push(D,d);
    	cin>>d;                            //���Ǻ����ķ���λ����
	}
	k=1;
	cin>>d;
	while(d!=')'){
		Push(SS,d);
		cin>>d;                            //���Ǻ����ĽǶȵķ�������
	}
	while(StackEmpty(SS)){
		t=SetS(SS,q);                      //���Ǻ����Ƕȵķ���ת��λ��ֵ
		t=t/180*pi;                        //���Ǻ����ĽǶ�ת��Ϊ����
	}
	Pop(D,ch);
	switch(ch){
		case 's':
			t=cos(t);break;
		case 't':
			t=atan(t);break;
		case 'n':
			Pop(D,ch);
			switch(ch){
			    case 'i':
				    t=sin(t);break;
			    case 'a':
				    t=tan(t);break;
		        default:break;
			}
			break;
		case 'c':
			Pop(D,ch);
			switch(ch){
			    case 's':
				    t=asin(t);break;
			    case 'e':
				    t=acos(t);break;
		        default:break;
			}
		default:break;                       //���Ǻ����ķ����ж��Լ������Ǻ�������ֵ����
	}
	while(StackEmpty(D)){
		Pop(D,ch);                           //���Dջ
	}
	Push(S,t);                               //�����Ǻ�����ֵ�洢��Sջ
}*/ 




void trigonometric(ChStack &H,CElemType &ch){
	char d=ch;
	double t,pi=3.14192653589793;
	ChStack D;
	InitStack(D);
	while(d=='c'||d=='o'||d=='s'||d=='a'||d=='t'||d=='n'||d=='i'){
		Push(D,d);
    	cin>>d;                            //���Ǻ����ķ���λ����
	}
	Pop(D,ch);
	switch(ch){
		case 's':
			Push(H,'c');break;
		case 't':
			Push(H,'a');break;
		case 'n':
			Pop(D,ch);
			switch(ch){
			    case 'i':
				    Push(H,'s');break;
			    case 'a':
				    Push(H,'t');break;
		        default:break;
			}
			break;
		case 'c':
			Pop(D,ch);
			switch(ch){
			    case 's':
				    Push(H,'i');break;
			    case 'e':
				    Push(H,'o');break;
		        default:break;
			}
		default:break;                       //���Ǻ����ķ����ж��Լ������Ǻ�������ֵ����
	}
	ch=d;
}




int main(){
	SqStack S;                               //����ջS
	ChStack SS;                              //���ݷ���ջSS
	ChStack H;                               //�������ջH
	InitStack(S);
	InitStack(SS);
	InitStack(H);                            //��ջ�ĳ�ʼ��            
	int n=0,q=0,t=0,o=0;
	int enter=1,re=0;
	double k,A;
	char e,ch;                               //��������ֵ
	cout<<"*****************************************************"<<endl;
	cout<<"**                  ���׵ļ�����                   **"<<endl;
	cout<<"*****************************************************"<<endl;
	cout<<"**ע�⣺1.�������������ڴ����ŵļӼ��˳���С������ **"<<endl;
	cout<<"**        �Ǻ���(sin,cos,tan,sec,cot,csc)�ļ��㡣  **"<<endl;
	cout<<"**                                                 **"<<endl;
	cout<<"**      2.�����ʽ�����Ǻ�����sin(30)              **"<<endl;
	cout<<"**                                                 **"<<endl;
	cout<<"**                                                 **"<<endl;
    cout<<"*****************************************************"<<endl;
	cout<<"**��ӭ����ʹ�ã���������������Ҫ�����ʽ��         **"<<endl;
	cout<<"*****************************************************"<<endl;
	cout<<"**������һ����ʽ(��#��β): ";
	cin>>ch;
	while(ch!='#'){
		switch(ch){
			case 's':
			case 't':
			case 'c':
				trigonometric(H,ch);enter=0;break;    //����Ϊs,t,cʱִ��trigonometric����
		    case '0':
		    case '1':
		    case '2':
		    case '3':
		    case '4':
		    case '5':
		    case '6':
		    case '7':
	    	case '8':
	    	case '9':
			case '.':
		    	Push(SS,ch);
				o=1;break;                  //�������ֵʱѹ�����ݷ���ջSS
			case '(':
				Pop(H,e);
				Push(H,e);
				if(e=='-'){
					q=0;
				    t=1;                            //�����롮����ʱ��ǰһ������Ϊ��-��������£�����ֵ���ű��q��0�����ŷ��ű��t��1
				}
				Push(H,ch);
				n=3;o=0;break;                          //�������ֱ��ѹ�����ջH����������˳������Ϊ3��
	    	case '+':
	    		o=1;
				while(StackEmpty(SS)){
		            k=SetS(SS,q);
		            Push(S,k);                      //�����ݷ���ջ�еķ���ת��Ϊ��ֵ�洢������ջS
				}
				if(n<1){
					Push(H,ch);
					n=1;break;
				}
				else if(n>=1&&n<3){
					count(S,H);
					Push(H,ch);
					n=1;break;
				}
				else if(n==3){
					Push(H,ch);
					n=4;break;
				}
				else if(n>=4){
					count(S,H);
					Push(H,ch);
					n=4;break;
				}                                  //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				Push(H,ch);
				n=1;break;                         //ѹ�����ջ����������˳������Ϊ1������˳���ǵ�ֵ��3����ʱ����4��
	    	case '-':
				if(StackEmpty(SS)){
		            k=SetS(SS,q);
		            Push(S,k);
				}else if(o==0) Push(S,0);
				if(n<1){
					Push(H,ch);
					if(q==1){
						q=0;
					}else q=1;
					n=1;break;
				}
				else if(n>=1&&n<3){
					count(S,H);
					Push(H,ch);
					if(q==1){
						q=0;
					}else q=1;
					n=1;break;
				}
				else if(n==3){
					Push(H,ch);
					if(q==1){
						q=0;
					}else q=1;
					n=4;break;
				}
				else if(n>=4){
					count(S,H);
					Push(H,ch);
					if(q==1){
						q=0;
					}else q=1;
					n=4;break;
				}                                    //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				Push(H,ch);
				if(q==1){
						q=0;
					}else q=1;
				n=1;break;                           //ѹ�����ջ����������˳������Ϊ1������˳���ǵ�ֵ��3����ʱ����4������ֵ���ű����1
	    	case '*':
	    		o=1;
				while(StackEmpty(SS)){
		            k=SetS(SS,q);
		            Push(S,k);
				}
				if(n<=1){
					Push(H,ch);
					n=2;break;
				}
				else if(n>=2&&n<3){
					count(S,H);
					Push(H,ch);
					n=2;break;
				}
				else if(n==3||n==4){
					Push(H,ch);
					n=5;break;
				}
				else if(n=5){
					count(S,H);
					Push(H,ch);
					n=5;break;
				}                                     //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				Push(H,ch);
				n=2;break;                            //ѹ�����ջ����������˳������Ϊ2������˳���ǵ�ֵ��3����ʱ����5��
	      	case '/':
	      		o=1;
				while(StackEmpty(SS)){
		            k=SetS(SS,q);
		            Push(S,k);
				}
				if(n<=1){
					Push(H,ch);
					n=2;break;
				}
				else if(n>=2&&n<3){
					count(S,H);
					Push(H,ch);
					n=2;break;
				}
				else if(n==3||n==4){
					Push(H,ch);
					n=5;break;
				}
				else if(n=5){
					count(S,H);
					Push(H,ch);
					n=5;break;
				}                                     //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				Push(H,ch);
				n=2;break;                            //ѹ�����ջ����������˳������Ϊ2������˳���ǵ�ֵ��3����ʱ����5��
	    	case ')':
				while(StackEmpty(SS)){
		            k=SetS(SS,q);
		            Push(S,k);
				}
				GetTop(H,e);
				while(e!='('){
					count(S,H);
					GetTop(H,e);
				}                                      //����������ʽ�ӵ�ֵ
				Pop(H,e);                              //ȥ������ջ�еġ�����
				while(re==0){
					GetTop(H,e);
				    switch(e){
				        case '0':
					    	n=0;re=1;break;
				     	case '+':
				    	case '-':
					    	n=1;re=1;break;
				    	case '*':
				    	case '/':
					    	n=2;re=1;break;
				    	case 'c':
				    	case 'a':
				    	case 's':
				    	case 't':
				    	case 'i':
				    	case 'o':
					    	count(S,H);break;
			    	}      
				}                                       //������ǰ�ķ����жϣ��ظ�����ǰ����˳���ǵ�ֵ
				re=0;
				
				if(t==1){
					Pop(S,k);
					k=0-k;
					t=0;
					Push(S,k);                         //�����ŷ��ű�ǵ�ֵ�ж��������ż�����������
				}
				break;
            default:break;
		}
		if(!enter)enter=1;
		else cin>>ch;
	}
	while(StackEmpty(SS)){
		k=SetS(SS,q);
		Push(S,k);
	}
	while(StackEmpty(H)){
		count(S,H);                                     //ʣ��ʽ�ӵļ���
	}
	if(syt==ERROR){
		cout<<"��ʽ��ʽ�������������룡 "<<endl;
	}else {
		Pop(S,A);
	    cout<<"**������                ="<<A<<endl;                           //������
	}
	return 0;
}
