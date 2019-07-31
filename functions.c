#include"header.h"
int search_uid(char s[])
{
        struct user s2;
        FILE *fp3;
        fp3=fopen("database","r");
        rewind(fp3);
        while(fread(&s2,sizeof(s2),1,fp3))
        {
                if(strcmp(s2.uid,s)==0)
                {
                        fclose(fp3);
                        return SUCCESS;
                }
        }
        fclose(fp3);
        return FAIL;
}
int search_pwd(char p[],char u[])
{
        struct user s2;
        FILE *fp3;
        fp3=fopen("database","r");
        rewind(fp3);
        while(fread(&s2,sizeof(s2),1,fp3))
        {
                if(strcmp(s2.pwd,p)==0&&strcmp(s2.uid,u)==0)
                {
                        fclose(fp3);
                        return SUCCESS;
                }
        }
        fclose(fp3);
        return FAIL;
}

int sign_up()
{
	struct user s1,s2;
	FILE *fp,*fp2;
	int i,u,j,p;
	printf("enter your name\n");
	__fpurge(stdin);
	fgets(s1.name,50,stdin);
	i=0;
	while(i<4)
	{
		printf("uid:\n");
	        __fpurge(stdin);
        	fgets(s1.uid,50,stdin);
        	u=search_uid(s1.uid);

		if(u==FAIL)
		break;
		else
		{
			printf("user id already exist \n");
			i++;
		}
		if(i==3)
		return FAIL;
	}
	printf("password:\n");
	__fpurge(stdin);
	fgets(s1.pwd,20,stdin);
	j=0;
	while(j<4)
	{
		printf("re enter your password:\n");
		__fpurge(stdin);
		fgets(s1.rpwd,20,stdin);
		if(strcmp(s1.pwd,s1.rpwd)==0)
		break;
		else
		{
			printf("password didn't matched\n");
	        	j++;

		}	
		if(j==3)
                return FAIL;
	}
	printf("dob:\n");
        __fpurge(stdin);
        fgets(s1.dob,20,stdin);
	printf("email:\n");
        __fpurge(stdin);
        fgets(s1.email,50,stdin);
        printf("phone number:\n");
        __fpurge(stdin);
        fgets(s1.m_no,20,stdin);
	
	fp=fopen("database","a+b");
	fwrite(&s1,sizeof(struct user),1,fp);
	fclose(fp);

	return SUCCESS;
}

int sign_in()
{
	int i,p,u,j;
	char str1[30],str2[30];
	i=0;
	while(i<4)
	{
		printf("enter your id\n");
		__fpurge(stdin);
		fgets(str1,50,stdin);
		p=search_uid(str1);
		if(p==FAIL)
		{
			printf("user id doesnt exist\n");
			i++;
		}
		else
		{
			i--;
			printf("user id exist\n");
			j=0;
			while(j<4)
			{
				printf("enter your password\n");
				__fpurge(stdin);
				fgets(str2,20,stdin);
				u=search_pwd(str2,str1);
				if(u==FAIL)
				{
					printf("password is invalid\n");
					j++;
				}	
				else
				{
					return SUCCESS;
				}
				if(j==3)
				return EMPTY;
			}
		}
		if(i==3)
		return FAIL;
	}
}
int add_song()
{
	struct song s1;
	FILE *fp;
	printf("enter the song name\n");
	__fpurge(stdin);
	fgets(s1.name,25,stdin);
	printf("enter the composer name\n");
	__fpurge(stdin);
	fgets(s1.composer,25,stdin);
	printf("enter the duration of song\n");
	scanf("%f",&s1.duration);
	printf("enter the rating\n");
	scanf("%d",&s1.rating);

	
	fp=fopen("songs","a+b");
        fwrite(&s1,sizeof(struct song),1,fp);
        fclose(fp);

	return SUCCESS;
}
int search(char s[])
{
	struct song s1;
	FILE *fp3;
        fp3=fopen("songs","r");
	rewind(fp3);
        while(fread(&s1,sizeof(s1),1,fp3))
        {
                if(strcmp(s1.name,s)==0)
                {
			fclose(fp3);
         		return SUCCESS;
                }
        }
	fclose(fp3);
	return FAIL;
}
int song_edit()
{
	struct song s1;
        FILE *fp1,*fp2;
        char str1[25];
	int u;
        printf("enter song name\n");
        __fpurge(stdin);
        fgets(str1,25,stdin);
	u=search(str1);
	if(u==FAIL)
	{
		printf("song is not found in the file\n");
		return FAIL;
	}
	else
	{
		printf("song is found\n");
		fp1=fopen("songs","r");
		fp2=fopen("tempfile","w");
		while(fread(&s1,sizeof(s1),1,fp1))
		{
			if(strcmp(s1.name,str1)!=0)
			fwrite(&s1,sizeof(s1),1,fp2);
			else
			{
				printf("enter the new song name\n");
        			__fpurge(stdin);
        			fgets(s1.name,25,stdin);
        			printf("enter the composer name\n");
        			__fpurge(stdin);
        			fgets(s1.composer,25,stdin);
        			printf("enter the duration of song\n");
        			scanf("%f",&s1.duration);
        			printf("enter the rating\n");
        			scanf("%d",&s1.rating);
				fwrite(&s1,sizeof(s1),1,fp2);
			}
		}
		fclose(fp1);
		fclose(fp2);
		fp1=fopen("songs","w");
                fp2=fopen("tempfile","r");
		while(fread(&s1,sizeof(s1),1,fp2))
		{
			fwrite(&s1,sizeof(s1),1,fp1);
		}
		fclose(fp1);
                fclose(fp2);
		printf("song is edited\n");
		return SUCCESS;
	}
}
int display_songs()
{
	struct song s1;
	FILE *fp1;
	fp1=fopen("songs","r");
	while(fread(&s1,sizeof(s1),1,fp1))
	{
		printf("song name: ");
		puts(s1.name);
		printf("song composer: ");
                puts(s1.composer);
		printf("song duration: ");
                printf("%f\n",s1.duration);
		printf("song rating: ");
                printf("%d\n",s1.rating);
	}
	fclose(fp1);
	return SUCCESS;
}
int search_song()
{
	struct song s1;
        FILE *fp1;
        char str1[25];
        int u;
        printf("enter song name\n");
        __fpurge(stdin);
        fgets(str1,25,stdin);
        u=search(str1);
        if(u==FAIL)
        {
                printf("song is not found in the file\n");
		return FAIL;
        }
        else
        {
 		printf("song is found\n");
                fp1=fopen("songs","r");
                while(fread(&s1,sizeof(s1),1,fp1))
                {
                        if(strcmp(s1.name,str1)==0)
			{
				printf("song name: ");
		                puts(s1.name);
                		printf("song composer: ");
                		puts(s1.composer);
                		printf("song duration: ");
                		printf("%f\n",s1.duration);
                		printf("song rating: ");
                		printf("%d\n",s1.rating);
				fclose(fp1);
				return SUCCESS;
			}
		}
	}
}
int delete_song()
{
	struct song s1;
        FILE *fp1,*fp2;
        char str1[25];
	int u;
        printf("enter the song you want to delete\n");
        __fpurge(stdin);
        fgets(str1,25,stdin);
	u=search(str1);
	if(u==FAIL)
	{
		printf("song is not found in the file\n");
		return FAIL;
	}
	else
	{
		printf("song is found\n");
		fp1=fopen("songs","r");
		fp2=fopen("tempfile","w");
		while(fread(&s1,sizeof(s1),1,fp1))
		{
			if(strcmp(s1.name,str1)!=0)
			fwrite(&s1,sizeof(s1),1,fp2);
		}
		fclose(fp1);
		fclose(fp2);
		fp1=fopen("songs","w");
                fp2=fopen("tempfile","r");
		while(fread(&s1,sizeof(s1),1,fp2))
		{
			fwrite(&s1,sizeof(s1),1,fp1);
		}
		fclose(fp1);
                fclose(fp2);
		printf("song is deleted\n");
		return SUCCESS;
	}
}
