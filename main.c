#include"header.h"
int main()
{
	int ch,u,p,n,a,h,l=0;
	for(;;)
	{
		printf("enter\n1:sign_up\n2:sign_in\n3.exit\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: h=sign_up();
				if(h==FAIL)
				{
					printf("sorry due to 3 continuos wrong input try doing from first\n");
					break;
				}
				else
				{
		        		printf("your are successfully signed up\n");
					l=1;
		        		break;		
				}
			case 2: u=sign_in();
		        	if(u==SUCCESS)
		    		{
					printf("your are successfully signed in\n");
					l=1;
					break;
				}
				else 
				{
					if(u==FAIL)
					printf("u typed 3 times invalid user id\n");
					if(u==EMPTY)
					printf("u typed 3 times invalid password\n");
					printf("so sign_in is failed\n");
					break;
				}
			case 3:  return EMPTY;
			default: printf("wrong choice\n");
		         	 return EMPTY;
		}
		if(l==1)
		break;
	}
	for(;;)
	{
		printf("enter to the music library\n");
		printf("enter \n1.add a new song\n2.search a song\n3.edit a song\n4.display all songs\n5.delete a song\n6.to exit from library\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:	add_song();
				break;
			case 2:	search_song();
				break;
			case 3: song_edit();
				break;
			case 4: display_songs();
				break;
			case 5: delete_song();
				break;	
			case 6: return EMPTY;
			default:printf("wrong choice\n");
				return EMPTY;
		}
	}
}
