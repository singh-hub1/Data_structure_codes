 void read_array(int arr[],int n)
    {
        int i;
      for(i=0;i<n;i++)
      {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
      }
    }

    void display_array(int arr[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
        printf("arr[%d]=%d\n",i,arr[i]);
        }
    }

   void bubble_sort(int arr[],int n)
   {
       int i,j,t,flag=-1,cmpcnt=-1,swapcnt=-1;
      for(i=1;i<n;i++)
       {
        flag=0; //assume no swapping
        for(j=0;j<n-i;j++)
        {
            cmpcnt++;
            if(arr[j]>arr[j+1])
            {
                swapcnt++;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                flag=1; //swapping happen
            }
        }
        if(flag==0)
         break;
    }
   printf("total compare=%d\n",cmpcnt);
   printf("total swapping=%d\n",swapcnt);
}

