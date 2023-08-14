#include<iostream>
#include<fstream>

using namespace std;

void to16(char *p1,char *p2)
{
    short s1=*p1/16,s2=*p1%16;
    if(-1<s1&&s1<10)
    {
	*p2=s1+48;
    }
    else
    {
	*p2=s1+55;
    }
    p2++;
    if(-1<s2&&s2<10)
    {
	*p2=s2+48;
    }
    else
    {
	*p2=s2+55;
    }
    p2++;
    *p2=44;
}

int main(int argc,char *argv[])
{
    if(argc==1)
    {
	printf("to_bytes -filename");
	return 0;
    }
    else if(argc==2)
    {
	ifstream f1(argv[1],ios::in|ios::binary);
	ofstream f2("output.txt",ios::ate|ios::binary);
	f1.seekg(0,ios::end);
	long long s=f1.tellg();
	char buf1,buf2[5]="0x";
	for(long long l=0;l<s;l++)
	{
	    f1.seekg(l,ios::beg);
            f1.read(&buf1,1);
	    to16(&buf1,buf2+2);
	    f2.seekp(5*l,ios::beg);
	    if(l==s-1)
	    {
	        f2.write(buf2,4);
	    }
	    else
	    {
		f2.write(buf2,5);
	    }
        }
	f1.close();
	f2.close();
        return 1;
    }
    else
    {
	return 0;
    }
}

