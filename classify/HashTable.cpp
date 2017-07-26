HashTable

开放定址法：
HashTable 
InitializeTable (  int  TableSize  ) 
{ 
    HashTable  H ; 
    int  i ;

    /*为散列表分配空间。*/ 
    /*有些编译器不支持为struct HashTable分配空间，声称这是一个不完全的结构， */ 
    /*可使用一个指向HashTable的指针为之分配空间。*/ 
    /*如：sizeof( Probe )，Probe作为HashTable在typedef定义的指针。*/ 
    H  =  malloc (  sizeof (  struct  HashTable  )  );

    /*散列表大小为一个质数。*/ 
    H -> TableSize  =  Prime ;

    /*分配表所有地址的空间。*/ 
    H -> Cells  =  malloc (  sizeof (  Cell  )   *  H -> TableSize  );

    /*地址初始为空。*/ 
    for (  i  =  0 ;  i  <  H -> TableSize ;  i ++  ) 
        H -> Cells [ i ]. info  =  Empty ;

    return  H ; 
}
查找空单元并插入：
Position 
Find (  ElementType  Key ,  HashTable  H  ) 
{ 
    Position  Current ; 
    int  CollisionNum ;

    /*冲突次数初始为0。*/ 
    /*通过表的大小对关键字进行处理。*/ 
    CollisionNum  =  0 ; 
    Current  =  Hash (  Key ,  H -> TableSize  );

    /*不为空时进行查询。*/ 
    while (  H -> Cells [ Current ]. info  !=  Empty  && 
        H -> Cells [ Current ]. Element  !=  Key  ) 
    { 
        Current  =  ++ CollosionNum  *  ++ CollisionNum ;

        /*向下查找超过表范围时回到表的开头。*/ 
        if (  Current  >=  H -> TableSize  ) 
            Current  -=  H -> TableSize ; 
    }

    return  Current ; 
}