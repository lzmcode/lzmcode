// BKDR Hash Function
unsigned int BKDRHash(char *str)  
{  
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..  
    unsigned int hash = 0;
    while (*str)  
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}
// AP Hash Function
unsigned int APHash(char *str)  
{  
    unsigned int hash = 0;  
    int i;  
   
    for (i=0; *str; i++)  
    {  
        if ((i & 1) == 0)  
        {  
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));  
        }  
        else  
        {  
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));  
        }  
    }
    return (hash & 0x7FFFFFFF);  
}  

