#include <cstdio>

using namespace std;

int main(int argc , const char *argv[])
{
    printf("Reading file \n");
    char arg[] = "vocabulary.txt";
    char arg1[] = "bow_vocab2.xml";
    FILE *fSource = fopen(arg,"r");
    FILE *fDest = fopen(arg1,"w");

    if(fSource == 0x0)
        printf("Invalid source file.\n");

    if(fDest == 0x0)
        printf("Invalid destin file.\n");

    unsigned count=0, wordPerLine = 4;
    char word[400];
    char ini[]="<?xml version=\"1.0\"?> \n<opencv_storage>\n<vocabulary type_id=\" opencv-matrix \"> \n  <rows>1000</rows> \n  <cols>128</cols> \n  <dt>f</dt> \n  <data>";
    char fim[]="</data></vocabulary>\n</opencv_storage>";
    while(fscanf(fSource,"%s",word) != -1)
    {
    if (count == 0)
	{
	fputs(ini,fDest);
	}
        count++;
        fputs(word,fDest);
        fputc(' ',fDest);
        if(count%wordPerLine == 0)
            fputc('\n',fDest);

    }
    fputs(fim,fDest);
    fclose(fSource);
    fclose(fDest);
    printf("Close File \n");
    return 0;
}

