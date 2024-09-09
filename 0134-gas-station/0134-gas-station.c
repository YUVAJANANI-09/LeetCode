int canCompleteCircuit(int *gas, int n1, int* cost, int n2)
{
    int i,gas_sum=0,cost_sum=0; 
    for(i=0;i<n1;i++)
    {
       gas_sum+=gas[i];
    }
    for(i=0;i<n2;i++)
    {
       cost_sum+=cost[i];
    } 
    if(gas_sum<cost_sum)
    {
        return -1;
    }
    int start=0; 
    int tank=0; //3 1 1   1 2 2 
    for(i=0;i<=n1-1;i++) //i=1
    {
     tank += (gas[i]-cost[i]); //tank=2 
     if(tank<0)
     {
      start=i+1; 
      tank=0;
     }
    }
   return start;   
}