#include<stdio.h>
#include<string.h>
#define SUCCESS 1
#define FAIL -1
#define EMPTY 0
struct user
{
	char name[20];
	char uid[20];
	char pwd[20];
	char rpwd[20];
	char dob[20];
	char email[50];
	char m_no[20];
};
struct song
{
        char name[25];
        char composer[25];
        float duration;
        int rating;
};

int sign_up();
int sign_in();
int add_song();
int search();
int song_edit();
int display_songs();
int search_song();
int delete_song();
int search_uid();
int search_pwd();
