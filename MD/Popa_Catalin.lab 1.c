#include <stdio.h>

void main()
{
    int num,r,i,j,value,varf;
    int settings;
    int a[10][10],b[10][10],c[10][10],v[20];
    int mo=-1,mi=-1;
    int u=0;
    int ml=0;

start:
    printf("***********************************\n");
    printf("Alegeti introducerea:\n1. Lista adiacenta\t\n2. Matrice Adiacenta\t\n3. Matricea Incidenta\n\n");
    printf("***********************************\n");
    printf("\nComanda selectata: \n");
    scanf("%d",&settings);
    system("cls");

    switch(settings)
    {
    case 1:
    {
        printf("***********************************\n");
        printf("\nIntroduceti numarul de varfuri: ");
        scanf("%d",&varf);
        printf("***********************************\n");
        printf("\nIntroduceti lista de adiacenta:\n");
        for(i=0; i<varf; i++)
        {
            for(j=0; j<varf; j++)
            {
                a[i][j]=0;
            }
        }
        for(i=0,value=0; i<varf; i++)
        {
            printf("%d - ",i+1);
            for(value=0; value<20; value++)
            {
                scanf("%d",&v[value]);
                if(v[value]==0)
                {
                    break;
                }
            }
            value=0;
            while(v[value]!=0)
            {
                a[i][v[value]-1]=1;
                value++;
            }
        }
        printf("***********************************\n");
        printf("\nMatricea de adiacenta:\n\n");
        for(i=0; i<varf; i++)
        {
            for(j=0; j<varf; j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        printf("***********************************\n");
        printf("\nMatricea de incidenta:\n\n");
        for(i=0; i<varf; i++)
        {
            for(j=0; j<varf; j++)
            {
                if(a[i][j]==1)
                {
                    u++;
                }
            }
        }
        for(i=0; i<u; i++)
        {
            for(j=0; j<varf; j++)
            {
                b[i][j]=0;
            }
        }
        for(i=0,r=0; i<u; i++)
        {
            for(j=0; j<varf; j++)
            {
                if(a[i][j]==1)
                {
                    b[r][i]=-1;
                    r++;
                    b[ml][j]=1;
                    ml++;
                }
            }
        }
        for(i=0; i<u; i++)
        {
            for(j=0; j<varf; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
        break;
    }
    case 2:
    {
        printf("***********************************\n");
        printf("Introduceti numarul de varfuri:");
        scanf("%d",&varf);
        printf("***********************************\n");
        printf("Introduceti matricea de adiacenta:\n");
        for (i=0; i<varf; i++)
            for (j=0; j<varf; j++)
                scanf("%d",&a[i][j]);
        for(i=0; i<varf; i++)
        {
            for (j=0; j<varf; j++)
                if(a[i][j]==1)
                    u++;
        }
        for (i=0; i<u; i++)
        {
            for(j=0; j<varf; j++)
            {
                b[i][j]=0;
            }
        }
        for(i=0,r=0; i<u; i++)
        {
            for(j=0; j<varf; j++)
            {
                if(a[i][j]==1)
                {
                    b[r][i]=-1;
                    r++;
                    b[ml][j]=1;
                    ml++;
                }
            }
        }
        printf("***********************************\n");
        printf("Matricea de incidenta:\n");
        for(i=0; i<u; i++)
        {
            printf("\n");
            for (j=0; j<varf; j++)
                printf("%d\t",b[i][j]);
        }
        printf("***********************************\n");
        printf("\n\nLista de adicenta:\n");
        for (i=0; i<varf; i++)
        {
            printf("\n %d- ",i+1);
            for(j=0; j<varf; j++)
            {
                if(a[i][j]==1)
                {
                    printf("%d,",j+1);
                }
            }
            printf("0");
        }
        break;
    }
    case 3:
    {
        printf("\nIntroduceti numarul de varfuri: ");
        scanf("%d",&varf);
        printf("\nIntroduceti numarul de arce: ");
        scanf("%d",&r);
        printf("\n\nIntroduceti matricea de incidenta:\n\n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<varf; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0; i<varf; i++)
        {
            for(j=0; j<varf; j++)
            {
                b[i][j]=0;
            }
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<varf; j++)
            {
                if(a[i][j]==-1)
                {
                    mo=j;
                }
                else if(a[i][j]==1)
                {
                    mi=j;
                }
            }
            if(mo!=-1 && mi!=-1)
            {
                b[mo][mi]=1;
            }
        }
        printf("***********************************\n");
        printf("\n*Matricea de adiacenta:\n\n");
        for(i=0; i<varf; i++)
        {
            for(j=0; j<varf; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
        printf("***********************************\n");
        printf("\n*Lista de adiacenta:\n");
        for(i=0; i<varf; i++)
        {
            printf("\n%d - ",i+1);
            for(j=0; j<varf; j++)
            {
                if(b[i][j]==1)
                {
                    printf("%d, ",j+1);
                }
            }
            printf("0");
        }
        printf("\n");
        break;
    }
    default:
    {
        printf("Alegeti 1 sau 2");
        goto start;
    }
    }
    printf("\n1)Continuare\n \n 0) Inchide programul\n \t ");
    scanf("%d",&num);
    if(num)
    {
        system("cls");
        goto start;
    }

    return 0;
}
