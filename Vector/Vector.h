#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <math.h>
#define PI 3.1415926

using namespace std;

template <typename T> class Vector
{
public:
    Vector(int n=0,const T *v=NULL)      //���캯��
    {
        if(n<=0)
        {
            N=0;
            Vec=NULL;
            return;
        }
        Vec=new T[n];
        for(int i=0; i<n; i++)
            Vec[i]=(v!=NULL?v[i]:0);
        N=n;
    }

    Vector(const Vector &x)            //������캯��
    {
        Vec=new T[x.N];
        for(int i=0; i<x.N; i++)
            Vec[i]=x.Vec[i];
        N=x.N;
    }

    ~Vector()                          //��������
    {
        if(Vec!=NULL)
        delete [] Vec;
    }

    Vector & operator=(const Vector<T> &v)   //�ֵ���������
    {
        if(&v!=this)
        {
            if(Vec)
                delete [] Vec;
            Vec=new T[v.N];
            for(int i=0; i<v.N; i++)
                Vec[i]=v.Vec[i];
            N=v.N;
        }
        return *this;
    }

    T GetData(int n) const            //��ȡ��������
    {
        return Vec[n-1];
    }

    int GetN() const                 //��ȡ����ά��
    {
        return N;
    }

    bool operator==(const Vector<T> &x) const    //����==��ϵ�����
    {
        int flag=0;
        if(N==x.N)
        {
            for(int i=0; i<N; i++)
                if(Vec[i]==x.Vec[i])
                    flag=1;
                else
                    flag=0;
        }
        return (flag==1?true:false);
    }

    bool operator!=(const Vector<T> &x) const    //����!=��ϵ�����
    {
        int flag=0;
        if(N==x.N)
        {
            for(int i=0; i<N; i++)
                if(Vec[i]==x.Vec[i])
                    flag=1;
                else
                    flag=0;
        }
        return (flag==0?true:false);
    }

    friend Vector operator + (const Vector &a,const Vector &b)     //�������
    {
        if(a.N!=b.N)
        {
            Vector temp;
            return temp;
        }
        Vector temp=a;
        for(int i=0; i<a.N; i++)
        {
            temp.Vec[i]=a.Vec[i]+b.Vec[i];
        }
        return temp;
    }

    friend Vector operator - (const Vector &a,const Vector &b)    //�������
    {
        if(a.N!=b.N)
        {
            Vector temp;
            return temp;
        }
        Vector temp=a;
        for(int i=0; i<a.N; i++)
        {
            temp.Vec[i]=a.Vec[i]-b.Vec[i];
        }
        return temp;
    }

    friend Vector operator * (const Vector &a,T n)              //��������
    {
        Vector temp=a;
        for(int i=0; i<a.N; i++)
        {
            temp.Vec[i]=a.Vec[i]*n;
        }
        return temp;
    }

    friend double DotX (const Vector &a,const Vector &b)      //�������
    {
        if(a.N!=b.N)
        {
            return 0;
        }
        double sum=0;
        for(int i=0; i<a.N; i++)
        {
            sum+=a.Vec[i]*b.Vec[i];
        }
        return sum;
    }

    friend Vector CrossX(const Vector &a,const Vector &b)       //��ά����ά�������
    {
        if(a.N!=b.N||a.N>3||b.N>3)
        {
            Vector temp;
            return temp;
        }
        Vector temp(3);
        if(a.N==3)
        {
            temp.Vec[0]=a.Vec[1]*b.Vec[2]-a.Vec[2]*b.Vec[1];
            temp.Vec[1]=a.Vec[2]*b.Vec[0]-a.Vec[0]*b.Vec[2];
            temp.Vec[2]=a.Vec[0]*b.Vec[1]-a.Vec[1]*b.Vec[0];
        }
        else if(a.N==2)
        {
            temp.Vec[0]=0;
            temp.Vec[1]=0;
            temp.Vec[2]=a.Vec[0]*b.Vec[1]-a.Vec[1]*b.Vec[0];
        }
        return temp;
    }

    double VecLen()                                      //��������(����ģ)
    {
        double sum=0;
        for(int i=0; i<N; i++)
            sum=sum+Vec[i]*Vec[i];
        return sqrt(sum);
    }

    friend double VecAngle (Vector &a,Vector &b)             //���������ļн�
    {
        double angle;
        angle=acos(DotX(a,b)/(a.VecLen()*b.VecLen()))*180/PI;
        return angle;
    }

    void Display()                                             //չʾ����
    {
        if(N<=0)
            cout<<"()"<<endl;
        else
        {
            cout<<"(";
            for(int i=0; i<N-1; i++)
            {
                cout<<Vec[i];
                cout<<",";
            }
            cout<<Vec[N-1];
            cout<<")";
            cout<<endl;
        }
    }

private:
    T *Vec;
    int N;
};



#endif // VECTOR_H_INCLUDED
