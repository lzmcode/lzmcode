HashTable

���Ŷ�ַ����
HashTable 
InitializeTable (  int  TableSize  ) 
{ 
    HashTable  H ; 
    int  i ;

    /*Ϊɢ�б����ռ䡣*/ 
    /*��Щ��������֧��Ϊstruct HashTable����ռ䣬��������һ������ȫ�Ľṹ�� */ 
    /*��ʹ��һ��ָ��HashTable��ָ��Ϊ֮����ռ䡣*/ 
    /*�磺sizeof( Probe )��Probe��ΪHashTable��typedef�����ָ�롣*/ 
    H  =  malloc (  sizeof (  struct  HashTable  )  );

    /*ɢ�б��СΪһ��������*/ 
    H -> TableSize  =  Prime ;

    /*��������е�ַ�Ŀռ䡣*/ 
    H -> Cells  =  malloc (  sizeof (  Cell  )   *  H -> TableSize  );

    /*��ַ��ʼΪ�ա�*/ 
    for (  i  =  0 ;  i  <  H -> TableSize ;  i ++  ) 
        H -> Cells [ i ]. info  =  Empty ;

    return  H ; 
}
���ҿյ�Ԫ�����룺
Position 
Find (  ElementType  Key ,  HashTable  H  ) 
{ 
    Position  Current ; 
    int  CollisionNum ;

    /*��ͻ������ʼΪ0��*/ 
    /*ͨ����Ĵ�С�Թؼ��ֽ��д���*/ 
    CollisionNum  =  0 ; 
    Current  =  Hash (  Key ,  H -> TableSize  );

    /*��Ϊ��ʱ���в�ѯ��*/ 
    while (  H -> Cells [ Current ]. info  !=  Empty  && 
        H -> Cells [ Current ]. Element  !=  Key  ) 
    { 
        Current  =  ++ CollosionNum  *  ++ CollisionNum ;

        /*���²��ҳ�����Χʱ�ص���Ŀ�ͷ��*/ 
        if (  Current  >=  H -> TableSize  ) 
            Current  -=  H -> TableSize ; 
    }

    return  Current ; 
}