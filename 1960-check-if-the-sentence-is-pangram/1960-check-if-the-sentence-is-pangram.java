class Solution {
    public static boolean checkIfPangram(String sentence) {
         sentence=sentence.toLowerCase();
            boolean[] alp=new boolean[26];
            for(int i=0;i<sentence.length();i++)
            {
                char c=sentence.charAt(i);
                if(c>='a'&&c<='z')
                {
                    int index=c-'a';
                    alp[index]=true;
                }
            }
            for(int i=0;i<26;i++)
            {
                if(!alp[i])
                return false;
            }
            return true;
        }
        public static void main(String args[])
        {
            Scanner sc=new Scanner(System.in);
            String sentence=sc.nextLine();
            boolean result= checkIfPangram(sentence);
            System.out.print(result);
            sc.close();
        
        }
    }
