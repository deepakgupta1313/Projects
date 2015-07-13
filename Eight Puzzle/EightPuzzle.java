package One;

//				FINAL Req
	
//				1	2	3
//				8		4	
//				7	6	5

import java.util.*;


class EPState implements Comparable<EPState>
{
	int a[][]=new int[3][3];
	int score;
	int p0x;
	int p0y;
	
	public EPState(int t[][])
	{
		a=new int[3][3];
		score=0;
		int i=0;
		int j=0;
		
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				a[i][j]=t[i][j];
				if(a[i][j]==0)
				{
					p0x=i;
					p0y=j;
				}
			}
		}
	}
	
	public int compareTo(EPState t)
	{
		return Integer.valueOf(this.score()).compareTo(t.score());
	}
	
	public int score()
	{
		int i=0;
		int j=0;
		int num=0;
		score=0;
		
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				num=a[i][j];
				
				switch(num)
				{
					case 1	:	score=score+Math.abs(i-0)+Math.abs(j-0);
								break;
								
					case 2	:	score=score+Math.abs(i-0)+Math.abs(j-1);
								break;
								
					case 3	:	score=score+Math.abs(i-0)+Math.abs(j-2);
								break;
								
					case 4	:	score=score+Math.abs(i-1)+Math.abs(j-2);
					break;
					
					case 5	:	score=score+Math.abs(i-2)+Math.abs(j-2);
					break;
					
					case 6	:	score=score+Math.abs(i-2)+Math.abs(j-1);
					break;
					
					case 7	:	score=score+Math.abs(i-2)+Math.abs(j-0);
					break;
					
					case 8	:	score=score+Math.abs(i-1)+Math.abs(j-0);
					break;
					
					default	:	score=score;				
					
				}
			}
		}
		
		return score;
	}
}

class EightPuzzle {
	
	static int current=0;
	static int end=0;
	
	static ArrayList<EPState> al=new ArrayList<EPState>();
	
	static PriorityQueue<EPState> pq=new PriorityQueue<EPState>();

	public static void main(String[] args) {
		
		//int a[][]={{1,2,3},{8,0,4},{7,6,5}};
		int a[][]={{2,8,3},{1,6,4},{7,0,5}};
		
		//int a[][]={{2,1,8},{3,0,7},{4,5,6}};
		int b[][]={{8,1,2},{3,0,7},{5,4,6}};
		
		int i=0,j=0;
		int p0x=1,p0y=1;
		printA(a);		
		
		EPState s=new EPState(a);
		//EPState s2=new EPState(b);
		
		//al.add(s2);
		al.add(0,s);
		
		System.out.println("SCORE	"+s.score());
		//System.out.println("SCORE	"+s2.score());
		
		pq.add(s);
		//pq.add(s2);
		
		//System.out.println(pq.poll().score());
		//System.out.println(pq.poll().score());
		
		solve();
	}
	
	public static void solve()
	{
		while(true)
		{
			EPState s=new EPState(pq.poll().a);
		
			moveLeft(s);
			moveUp(s);
			moveRight(s);
			moveDown(s);
		}
	}
	
	public static boolean isNState(EPState t)
	{
		boolean n=false;
		int i=0,j=0,k=0;
		
		for(i=0;i<=end;++i)
		{
			EPState t2=al.get(i);
			n=false;
			for(j=0;j<3;++j)
			{
				for(k=0;k<3;++k)
				{
					//System.out.println(t.a[j][k]+"	"+t2.a[j][k]);
					
					if(t.a[j][k]!=t2.a[j][k])
					{
						n=true;
						break;
					}
				}
				if(n)
				{
					break;
				}
			}
			
			if(!n)
			{
				break;
			}
			
		}
		
		return n;
	}
	
	public static void moveLeft(EPState s)
	{
		System.out.println("LEFT	"+end+"	"+s.score());
		
		if(s.score()==0)
		{
			System.out.println("SOLVED");
			printA(s.a);
			System.exit(0);
		}
		
		if(s.p0y>0)
		{
			System.out.println("IN LLLLLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOO");
			EPState s2=new EPState(s.a);
			
			s2.a[s.p0x][s.p0y]=s2.a[s.p0x][s.p0y-1];
			s2.a[s.p0x][s.p0y-1]=0;
			s2.p0y=s.p0y-1;
			s2.p0x=s.p0x;
			
			if(isNState(s2))
			{
				++end;
				pq.add(s2);
				al.add(end,s2);
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	
	public static void moveRight(EPState s)
	{
		System.out.println("RIGHT	"+end+"	"+s.score());
		if(s.score()==0)
		{
			System.out.println("SOLVED");
			printA(s.a);
			System.exit(0);
		}
		
		if(s.p0y<2)
		{
			System.out.println("IN RRRRRRRRRRRRRROOOOOOOOOOOOOOOOOOO");
			EPState s2=new EPState(s.a);
			
			s2.a[s.p0x][s.p0y]=s2.a[s.p0x][s.p0y+1];
			s2.a[s.p0x][s.p0y+1]=0;
			s2.p0y=s.p0y+1;
			s2.p0x=s.p0x;
			
			if(isNState(s2))
			{
				++end;
				pq.add(s2);
				al.add(end,s2);
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	
	public static void moveUp(EPState s)
	{
		System.out.println("UP	"+end+"	"+s.score());
		if(s.score()==0)
		{
			System.out.println("SOLVED");
			printA(s.a);
			System.exit(0);
		}
		
		if(s.p0x>0)
		{
			System.out.println("IN UUUUUUUUUUUUUUUUUUUOOOOOOOOOOOOOOOOOOOO");
			EPState s2=new EPState(s.a);
			
			s2.a[s.p0x][s.p0y]=s2.a[s.p0x-1][s.p0y];
			s2.a[s.p0x-1][s.p0y]=0;
			s2.p0y=s.p0y;
			s2.p0x=s.p0x-1;
			
			if(isNState(s2))
			{
				++end;
				pq.add(s2);
				al.add(end,s2);
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	
	public static void moveDown(EPState s)
	{
		System.out.println("DOWN	"+end+"	"+s.score());
		if(s.score()==0)
		{
			System.out.println("SOLVED");
			printA(s.a);
			System.exit(0);
		}
		
		if(s.p0x<2)
		{
			System.out.println("IN DDDDDDDDDDDDDDDOOOOOOOOOOOOOOOOOOOO");
			EPState s2=new EPState(s.a);
			
			s2.a[s.p0x][s.p0y]=s2.a[s.p0x+1][s.p0y];
			s2.a[s.p0x+1][s.p0y]=0;
			s2.p0y=s.p0y;
			s2.p0x=s.p0x+1;
			
			if(isNState(s2))
			{
				++end;
				pq.add(s2);
				al.add(end,s2);
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}

	public static void printA(int a[][])
	{
		int i=0;
		int j=0;
		
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				System.out.print(a[i][j]+"\t");
			}
			System.out.println();
		}
	}
}
