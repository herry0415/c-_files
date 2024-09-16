#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <tchar.h>
#include <pthread.h> 
#include <time.h>
#include <string.h>
#include <sys/time.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
_TCHAR buffer[25][80] = { _T(' ') };
_TCHAR ramp[] = _T(".:-=+*#%@");

WORD hjzgg_color[7]={
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED | BACKGROUND_RED|BACKGROUND_GREEN,
    
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_GREEN | BACKGROUND_RED|BACKGROUND_GREEN,
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_BLUE | BACKGROUND_RED|BACKGROUND_GREEN,
    
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE | BACKGROUND_RED|BACKGROUND_GREEN,
    
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN | BACKGROUND_RED|BACKGROUND_GREEN,
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE | BACKGROUND_RED|BACKGROUND_GREEN,
    BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE | BACKGROUND_RED|BACKGROUND_GREEN
    
};

float f(float x, float y, float z)
{
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z)
{
    for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
        return y;
    return 0.0f;
}

char flower1[11][22]={
"         {@}        ",
"      {@} * {@}     ",
"   {@} * {@} * {@}  ",
"{@}* {@} * {@} * {@}",
" \\ {@} * {@} * {@} /",
"    \\ \\ \\ ## / / /   ",
"     \\\\ \\ ##/ //    ",
"       \\\\ ## //      ",
"        \\\\##//       ",//“##部分可自己换”
"         >=<        ",
"        //*\\\\       "
};

char flower2[9][28]={
".....@---------------@.....",
"-- @ @ @ --------- @ @ @ --",
".@ @\\@/@ @---L---@ @\\@/@ @.",
".\\@|@|@|@/-..O.--\\@|@|@|@/.",
". \\\\\\|/// --.V--- \\\\\\|/// -",
" - \\\\|// --..E---- \\\\|//.--",
" -- \\|/--..--#.---- \\|/---.",//此部分可是喜欢人的首拼
" -- =&= ---..#----- =&= ---",//此部分可是喜欢人的首拼
" -- /|\\ --------.---/|\\ -.-"
} ;

char piercing_arrow[][34]={
"                 ",
"                       ",
"    祝福的话啦（自己写）   ",
"                         ",
">>>----2022顺顺当当健健康康----->",
"                         ",
"                         ",
"                         ",
"                             "
};

char love_word[][100][100]={ 
    {
        "其  实  我  已  经  很  勇  敢  了",
        "也  许  未  来  很  长  一  段  时  间",
        "我  们  依  旧  会  远  隔  山  海",
        "但  我  永  远  不  会  忘  记", 
        "初  次  与  你  相  拥  时  的  心  动"
    } ,
    {
        "每  个  想  你  的  夜  都  只  有  月  亮  经  过",
        "不  见  面  的  日  子  里",
        "我  对  你  的  思  恋  只  会  更  加  浓  烈"
    },
//可以重复写很多情话，模板套用上述就可

};
void init_screen()
{
    COORD size = {100, 40};
    SetConsoleScreenBufferSize(o, size);
    SMALL_RECT rc = {0, 0, 100-1, 40-1};
    SetConsoleWindowInfo(o, true, &rc);
    SetConsoleTitle("For npy的名字");
    system("color ec");
}

void* show_love_word(void* arg){
    srand((unsigned)time(NULL));
    while(true) {
        int word_index = rand()%5;
        int col = 70;
        int row_index = 3;
        if(word_index == 4)
            row_index = 6;
        int color_index = rand()%4; 
        for(int i=0; i<row_index; ++i)
		{
            int row = 1;
            for(int j=0; love_word[word_index][i][j]; j+=2)
			{
                char one_word[2];
                sprintf(one_word, "%c%c", love_word[word_index][i][j], love_word[word_index][i][j+1]);
                COORD coord = {col, row};
                pthread_mutex_lock(&mutex);
                SetConsoleTextAttribute(o, hjzgg_color[color_index]);
                SetConsoleCursorPosition(o, coord);
                WriteConsole(o, one_word, 2, NULL, 0);
                coord.Y += 1;
                if(love_word[word_index][i][j+2])
				{
                    SetConsoleCursorPosition(o, coord);
                    WriteConsole(o, "__", 2, NULL, 0);
                }
                SetConsoleTextAttribute(o, hjzgg_color[0]);
                pthread_mutex_unlock(&mutex);
                ++row;
                Sleep(100);
            }
            col+=4;
        }
        
        Sleep(2000);

        col-=4;
        for(int i=row_index-1; i>=0; --i)
		{
            char hjzgg_word[60];
            memcpy(hjzgg_word, love_word[word_index][i],sizeof(love_word[word_index][i]));
            int len_hjzgg_word = strlen(hjzgg_word);
            int len_word = len_hjzgg_word;
            bool is_first = true;
            while(len_word >= 0) {
                int row = 1;
                for(int j=0; j<len_hjzgg_word; j+=2)
				{
                    char one_word[2];
                    sprintf(one_word, "%c%c", hjzgg_word[j], hjzgg_word[j+1]);
                    COORD coord = {col, row};
                    pthread_mutex_lock(&mutex);
                    SetConsoleTextAttribute(o, hjzgg_color[color_index]);
                    SetConsoleCursorPosition(o, coord);
                    WriteConsole(o, one_word, 2, NULL, 0);
                    coord.Y += 1;
                    if(j+2 == len_word){
                        SetConsoleCursorPosition(o, coord);
                        WriteConsole(o, "__", 2, NULL, 0);
                        ++row;
                    }
                    SetConsoleTextAttribute(o, hjzgg_color[0]);
                    pthread_mutex_unlock(&mutex);
                    ++row;
                }
                if(is_first){
                    is_first = false;
                    hjzgg_word[len_hjzgg_word++] = ' ';
                    hjzgg_word[len_hjzgg_word++] = ' ';
                } else {
                    len_hjzgg_word-=2;
                }
                hjzgg_word[--len_word] = ' ';
                hjzgg_word[--len_word] = ' ';
                Sleep(20);
            }
            col-=4;
        }
        Sleep(1000);
    }
}

void* first_init_top(void* arg)
{
    char tmp[80];
    for(int ld=0; ld < 12; ++ld)
	{
        COORD coord_top = { 0, ld};
        memset(tmp, ' ', sizeof(tmp));
        int cc = 0;
        while(cc < 60){
            while(buffer[ld][cc]==' ') ++cc;
            tmp[cc] = buffer[ld][cc];
            ++cc;
            pthread_mutex_lock(&mutex);
            SetConsoleCursorPosition(o, coord_top);
            WriteConsole(o, tmp, 60, NULL, 0);
            pthread_mutex_unlock(&mutex);
            Sleep(15);
        }
    }
}

void* screen_down_flower(void* arg)
{
    srand((unsigned)time(NULL));
    int flower_row[3] = {11, 9, 11};
    int flower_col[3] = {20, 27, 20};
    int flower_begin_col[3] = {5, 33, 70};
    int flower_begin_row[3] = {26, 28, 26};
    struct timeval now;
    struct timespec outtime;
    pthread_mutex_lock(&mutex);
    while(true)
	{
        int k = 0;
        while(k < 3)
		{
            char flower[50][50] = {' '};
            int color_index = rand()%7;
            SetConsoleTextAttribute(o, hjzgg_color[color_index]);
            if(k==0 || k==2)
			{
                for(int i=0; i<flower_row[k]; ++i)
                    for(int j=0; j<flower_col[k]; ++j)
                        flower[i][j] = flower1[i][j];
            } else 
			{
                for(int i=0; i<flower_row[k]; ++i)
                    for(int j=0; j<flower_col[k]; ++j)
                        flower[i][j] = flower2[i][j];
            }
            for(int i=flower_begin_row[k], j=0; j<flower_row[k]; ++j, ++i)
			{
                COORD coord = {flower_begin_col[k], i};
                SetConsoleCursorPosition(o, coord);
                WriteConsole(o, flower[j], flower_col[k], NULL, 0);
            }
            ++k;
            SetConsoleTextAttribute(o, hjzgg_color[0]);
            
            gettimeofday(&now, NULL);
            outtime.tv_sec = now.tv_sec;
            outtime.tv_nsec = now.tv_usec * 100000;
            pthread_cond_timedwait(&cond, &mutex, &outtime);
        } 
    }
    pthread_mutex_unlock(&mutex);
} 

void* first_init_down(void* arg)
{
    char tmp[80];
    for(int rd=24; 12 <= rd; --rd)
	{
        COORD coord_down = { 0, rd };
        SetConsoleCursorPosition(o, coord_down);
        memset(tmp, ' ', sizeof(tmp));
        int cc = 60;
        while(cc >= 0)
		{
            while(buffer[rd][cc]==' ') --cc;
            tmp[cc] = buffer[rd][cc];
            --cc;
            pthread_mutex_lock(&mutex);
            SetConsoleCursorPosition(o, coord_down);
            WriteConsole(o, tmp, 60, NULL, 0);
            pthread_mutex_unlock(&mutex);
            Sleep(15);
        }
    }
}

void show_piercing_arrow()
{
    for(int i=0; i<9; ++i) 
	{
        pthread_mutex_lock(&mutex);
        COORD coord_down = { 13, i+7 };
        SetConsoleCursorPosition(o, coord_down);
        WriteConsole(o, piercing_arrow[i], 33, NULL, 0);
        pthread_mutex_unlock(&mutex);
    }
}

void first_init()
{
    show_piercing_arrow();
    pthread_t tid[4];
    pthread_create(&tid[2], NULL, screen_down_flower, NULL); 
    pthread_create(&tid[3], NULL, show_love_word, NULL);  
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&tid[0], NULL, first_init_top, NULL); 
    pthread_create(&tid[1], NULL, first_init_down, NULL); 
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
}

int main() 
{
    init_screen();
    bool first = true;
    for (float t = 0.0f;; t += 0.1f)
	{
        int ec = 0;
        float s = sinf(t);
        float a = s * s * s * s * 0.2f;
        for (float z = 1.3f; z > -1.2f; z -= 0.1f) 
		{
            _TCHAR* p = &buffer[ec++][0];
            float tz = z * (1.2f - a);
            for (float x = -1.5f; x < 1.5f; x += 0.05f) 
			{
                float tx = x * (1.2f + a);
                float v = f(tx, 0.0f, tz);
                if (v <= 0.0f) {
                    float y0 = h(tx, tz);
                    float ny = 0.01f;
                    float nx = h(tx + ny, tz) - y0;
                    float nz = h(tx, tz + ny) - y0;
                    float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                    float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                    *p++ = ramp[(int)(d * 5.0f)];
                }
                else
                    *p++ = ' ';
            }
        }
        if(first)
		{
            first = false;
            first_init();
        }
        else {
            pthread_mutex_lock(&mutex);
            for (ec = 0; ec < 25; ec++) 
			{
                COORD coord = { 0, ec };
                SetConsoleCursorPosition(o, coord);
                WriteConsole(o, buffer[ec], 60, NULL, 0);
            }
            pthread_mutex_unlock(&mutex);
        }
        Sleep(33);
    }
    return 0;
}
