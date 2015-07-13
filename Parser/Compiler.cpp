#include<string>
#include<iostream>
#include<vector>

using namespace std;


void sortt(char *s)
{
 if(strcmp(s,"-1"))
 {
  int dd[50];
  int ff=0;
  char *ss=strtok(s,",");
  while(ss!=NULL)
  {
   dd[ff]=atoi(ss);
   ff++;
   ss=strtok(NULL,",");
  }
  
  for(int i=0;i<ff;i++)
  {
   for(int j=1;j<ff-i;j++)
   {
    if(dd[j-1]>dd[j])
    {
     int temp=dd[j];
     dd[j]=dd[j-1];
     dd[j-1]=temp;
    }
   }
  }
  
  strcpy(s,"");
  char bb[50][50];
  itoa(dd[0],bb[0],10);
  strcpy(s,bb[0]);
  for(int i=1;i<ff;i++)
  {
   strcat(s,",");
   itoa(dd[i],bb[i],10);
   strcat(s,bb[i]);
  }
 }
 cout<<"SORTT"<<s<<"SORTT"<<endl;
}


void getAbsilon(char *matrix[][6],char t[][50],int *currentp,int *endp,int rown)
{
 if(*currentp>*endp)
 {
  return;               
 } 
 
 int temp=atoi(t[*currentp]);
 if(strcmp(matrix[temp][3],"-1"))
 {
  bool valid=true;
  for(int k=0;k<=*endp;k++)
  {
   if(strcmp(matrix[temp][3],t[k])==0)
   {
     valid=false;
     break;
   }
  }
  if(valid)
  {
   printf("ff%sff\n",matrix[temp][3]);
   (*endp)++;
   strcpy(t[*endp],matrix[temp][3]);                               
  }                               
 }
 
 if(strcmp(matrix[temp][4],"-1"))
 {
  bool valid=true;
  for(int k=0;k<=*endp;k++)
  {
   if(strcmp(matrix[temp][4],t[k])==0 )
   {
     valid=false;
     break;
   }
  }
  if(valid)
  {
   printf("dd%sdd\n",matrix[temp][4]);
   (*endp)++;
   strcpy(t[*endp],matrix[temp][4]);                               
  }
 }
 
 (*currentp)++; 
 getAbsilon(matrix,t,currentp,endp,rown);
}

void getA(char *matrix[][6],char *mat[][5],char tt[][50],int *ccp,int *eep)
{
 cout<<"MAToo"<<mat[0][0]<<"MAToo"<<endl; 
 for(int nn=0;nn<50;nn++)
 {
  strcpy(tt[nn],"-1");
 }
 char *ch="";
 int c=0,e=0;
 int temp;
 char *temp2=(char *)malloc(50);
 char *temp3=(char *)malloc(50);
 strcpy(temp3,mat[*ccp][0]);
 cout<<"DD"<<mat[*ccp][0]<<"DD"<<endl;
 ch=strtok(temp3,",");
 while(ch!=NULL)
 {
  temp=atoi(ch);
  //temp2=matrix[temp][1];
  strcpy(temp2,matrix[temp][1]);
  cout<<"                      CH        "<<ch<<"    "<<"dd"<<temp2<<"dd"<<endl;
  //cout<<temp2<<endl;
  
  if(strcmp(temp2,"-1"))
  {
   
   bool v=true;
   for(int j=0;j<=e;j++)
   {
    cout<<"CMP                 "<<"qq"<<temp2<<"qq"<<"           "<<"qq"<<tt[j]<<"qq"<<endl;
    if(!strcmp(temp2,tt[j]))
    {
     v=false;
     break;                
    }
   }
   if(v)
   {
    strcpy(tt[e],temp2);
    cout<<"AA"<<tt[e]<<"AA"<<endl;
    e++;     
   }
  }
  ch=strtok(NULL,",");
 }
 
 int em=e;
 
 cout<<"CheckA                                    "<<mat[*ccp][0]<<"            ";
 
 for(int mm=0;mm<e;mm++)
 {
  cout<<tt[mm]<<" ";
 }
 cout<<endl;
 
 for(int i=0;i<em;i++)
 {
  int q=atoi(tt[i]);
  char *w="";
  
  char *temp4=(char *)malloc(50);
  strcpy(temp4,matrix[q][5]);
  
  w=strtok(temp4,",");
  while(w!=NULL)
  {
   
   bool y=true;
   for(int r=0;r<e;r++)
   {
    if(!strcmp(tt[r],w))
    {
     y=false;
     break;
    }
   }
   if(y)
   {
    strcpy(tt[e],w);
    cout<<"AA"<<tt[e]<<"AA"<<endl;
    e++;     
   }
   w=strtok(NULL,",");                 
  }
 }
 
 mat[*ccp][1]=(char *)malloc(50);
 strcpy(mat[*ccp][1],tt[0]);
 
 for(int gg=1;gg<e;gg++)
 {
  strcat(mat[*ccp][1],",");   
  strcat(mat[*ccp][1],tt[gg]);     
 }
 
 if(e>0)
 {
  
  sortt(mat[*ccp][1]);
  bool neww=true;
  for(int u=0;u<=*eep;u++)
  {
    if(!strcmp(mat[u][0],mat[*ccp][1]))
    {
     neww=false;
     break;
    }       
  }
  if(neww)
  { 
   ++(*eep);
   printf("EEP %d\n",*eep);
   mat[*eep][0]=(char *)malloc(50);
   strcpy(mat[*eep][0],mat[*ccp][1]); 
   cout<<"EEE"<<mat[*eep][0]<<"EEE"<<endl;        
  }
 }
}
void getB(char *matrix[][6],char *mat[][5],char tt[][50],int *ccp,int *eep)
{
 cout<<"BBBMAToo"<<mat[0][0]<<"BBBMAToo"<<endl; 
 for(int nn=0;nn<50;nn++)
 {
  strcpy(tt[nn],"-1");
 }
 char *ch="";
 int c=0,e=0;
 int temp;
 char *temp2=(char *)malloc(50);
 char *temp3=(char *)malloc(50);
 strcpy(temp3,mat[*ccp][0]);
 cout<<"BB"<<mat[*ccp][0]<<"BB"<<endl;
 ch=strtok(temp3,",");
 while(ch!=NULL)
 {
  
  temp=atoi(ch);
  //temp2=matrix[temp][2];
  strcpy(temp2,matrix[temp][2]);
  
  //cout<<temp2<<endl;
  
  if(strcmp(temp2,"-1"))
  {
   
   bool v=true;
   for(int j=0;j<=e;j++)
   {
    if(!strcmp(temp2,tt[j]))
    {
     v=false;
     break;                
    }
   }
   if(v)
   {
    strcpy(tt[e],temp2);
    cout<<"AA"<<tt[e]<<"AA"<<endl;
    e++;     
   }
  }
  ch=strtok(NULL,",");
 }
 
 int em=e;
 
 cout<<"CheckB                            "<<mat[*ccp][0]<<"            ";
 
 for(int mm=0;mm<e;mm++)
 {
  cout<<tt[mm]<<" ";
 }
 cout<<endl;
 
 for(int i=0;i<em;i++)
 {
  int q=atoi(tt[i]);
  char *w="";
  
  char *temp4=(char *)malloc(50);
  strcpy(temp4,matrix[q][5]);
  
  w=strtok(temp4,",");
  
  while(w!=NULL)
  {
   
   bool y=true;
   for(int r=0;r<e;r++)
   {
    if(!strcmp(tt[r],w))
    {
     y=false;
     break;
    }
   }
   if(y)
   {
    strcpy(tt[e],w);
    cout<<"AA"<<tt[e]<<"AA"<<endl;
    e++;     
   }
   w=strtok(NULL,",");                 
  }
 }
 
 mat[*ccp][2]=(char *)malloc(50);
 strcpy(mat[*ccp][2],tt[0]);
 
 for(int gg=1;gg<e;gg++)
 {
  strcat(mat[*ccp][2],",");   
  strcat(mat[*ccp][2],tt[gg]);     
 }
 
 if(e>0)
 {
  
  sortt(mat[*ccp][2]);
  bool neww=true;
  for(int u=0;u<=*eep;u++)
  {
    if(!strcmp(mat[u][0],mat[*ccp][2]))
    {
     neww=false;
     break;
    }       
  }
  if(neww)
  {
   ++(*eep);
   mat[*eep][0]=(char *)malloc(50);
   strcpy(mat[*eep][0],mat[*ccp][2]); 
   cout<<"NNN"<<mat[*eep][0]<<"NNN"<<endl;      
  }
 }   
 
}


int main()
{
	FILE *fp;
	char buff[50][200];
	char *matrix[50][6];
	char *ch;
	int i=0;
	int j=0;
	int rows=0,columns=0;

	if((fp=(FILE *)fopen("Compiler.txt","r"))==NULL)
	{
		printf("Unable to read from text file");
		cin.get();
		exit(0);
	}
	
	while(fgets(buff[i],1500,fp)!=NULL)
	{
     if(i!=0)
     {
      int ll=0;
      while(buff[i][ll]!='\n')
      {
       ll++;
      }
      buff[i][ll]='\0';
      
      ch=strtok(buff[i],"\t");
      while(ch!=NULL)
      { 
        matrix[i-1][j]=ch;                                
        printf("%s\t",matrix[i-1][j]);
        ch=strtok(NULL,"\t");
        j++;
      }
     }
     printf("\n");
      i++;
      rows++;
      columns=j;
      j=0;
    }
    --rows;
    printf("RRRRRRRRR %d    CCCCCCCCCCCCC %d\n",rows,columns);
    for(i=0;i<rows;i++)
    {
      char t[50][50];
      int current=0,end=0;
      strcpy(t[0],matrix[i][0]);
      printf("%s\n",t[0]);
      getAbsilon(matrix,t,&current,&end,i);
      
      matrix[i][5]=(char *)malloc(50);
      strcpy(matrix[i][5],matrix[i][0]);
      int p=1;
      while(p<=end)
      {
        strcat(matrix[i][5],",");
        strcat(matrix[i][5],t[p]);
        p++;           
      }
      cout<<"STR"<<matrix[i][5]<<"STR"<<endl;
    }
    
    sortt(matrix[4][5]);
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    for(int h=0;h<rows;h++)
    {
     for(int z=0;z<columns+1;z++)
     {
      printf("%s\t",matrix[h][z]);        
     }
     cout<<endl;
    }
    
    char *mat[50][5];
    int cc=0,ee=0;
    
    mat[0][0]=(char *)malloc(50);
    
    sortt(matrix[0][5]);
    strcpy(mat[0][0],matrix[0][5]);
    printf("XX%sXX\n",mat[0][0]);
    
    for(int i=0;i<=ee;i++)
    {
     char tt[50][50];
     //mat[i][0]=(char *)malloc(50);
     getA(matrix,mat,tt,&cc,&ee);
     
     char tt2[50][50];
     //mat[i][1]=(char *)malloc(50);
     getB(matrix,mat,tt2,&cc,&ee); 
     ++cc;       
    }
    
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    for(int h=0;h<rows;h++)
    {
     for(int z=0;z<columns+1;z++)
     {
      printf("%s\t",matrix[h][z]);        
     }
     cout<<endl;
    }
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    for(int h=0;h<=ee;h++)
    {
     for(int z=0;z<3;z++)
     {
      printf("%s\t\t",mat[h][z]);       
     }
     cout<<endl;
    }
    
    cin.get();
	return 0;
}
