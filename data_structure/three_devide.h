double three_devide(double low,double up)  
{  
    double m1,m2;  
    while(up-low>=eps)  
    {  
        m1=low+(up-low)/3;  
        m2=up-(up-low)/3;  
        if(f(m1)<=f(m2))  
            low=m1;  
        else  
            up=m2;  
    }  
    return (m1+m2)/2;  
}
