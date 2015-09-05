class SumN {
   public int sum(int start, int end, int acc){
       if(start==end) return start+acc;
       else
          return sum(start+1,end,acc+start);
   }
   
   public int sumhelper(int start, int end){
      return sum(start,end,0);
   }
   public static void main(String[] args) {
      SumN obj = new SumN();
      System.out.println(obj.sumhelper(1,5));
   }
}