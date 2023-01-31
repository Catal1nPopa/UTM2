#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    char teme[5][1000] =
    {
        "Intrebari despre tara natala",
        "Intrebari despre animale",
        "Intrebari despre planeta",
        "Intrebari despre organismul uman",
        "Intrebari despre istorie"
    };
    char q[15][15][1000] =
    {
        {
            "Cum se numeste tara unde locuiesti?\n",
            "Care este capitala tarii?\n",
            "Care este cel mai mare oras din tara?\n",
            "Numele presedintelui tarii\n",
            "In ce oras se afla aeroportul?\n",
            "Care este strada principala din Chisinau?\n",
            "Care este cea mai lunga strada din chisinau?\n",
            "Densitatea populatiei?\n",
            "Care este cel mai populat sector al capitalei?\n",
            "Care este densitatea populatiei capitalei?\n",
            "Cine sunt vecinii de west ai tarii?\n",
            "Care este suprafata tarii?\n",
            "Care anotimpuri sunt frecvente in tara?\n",
            "Ce tip de relief este specific tarii?\n",
            "Ce sol este cel mai frecvent?\n"
        },//tema 2
        {
            "Cel mai rapid animal?\n",
            "Cel mai mic animal din lume?\n",
            "Cel mai puternic animal?\n",
            "Cel mai greu animal?\n",
            "Cel mai periculos animal?\n",
            "Care animal este domestic?\n",
            "Care animal este salbatic?\n",
            "Ce animal nu este raspandit in Moldova?\n",
            "Cel mai mare organism acvatic?\n",
            "Care animal este carnivor?\n",
            "Care animal este erbivor?\n",
            "Ce animal este considerat cel mai bun prieten al omului?\n",
            "La care animal resperatia are loc prin piele?\n",
            "Cat timp isi digera mancarea un lenes?\n",
            "Care este tara de origine a limurilor?\n",
        },//tema 3
        {
            "Care dintre straturile Pamantului poate fi asociat cu conditiile meterologice?\n",
            "Care este singurul  continent acoperit in intregime cu gheata?\n",
            "Cum este numita zona centrala a Pamantului?\n",
            "Care este singurul continent unde tigrul poate fi gasit in salbaticie?\n",
            "In ce parte a troposferei exista viata?\n",
            "A cata planeta este Pamantul?\n",
            "Care este cea mai rece planeta?\n",
            "Prima planeta de langa soare?\n",
            "Planeta care urmeaza sa fie populata?\n",
            "Ce este soarele?\n",
            "Cate procente constituie apa din planeta Pamant?\n",
            "Care este satelitul natural al Pamantului?\n",
            "A doua cea mai mica planeta din sistemul solar?\n",
            "Prima planeta cea mai mica din sistemul solar?\n",
            "Cate planete din sistemul solar au inele?\n"
        },//tema 4
        {
            "Cel mai lung os al corpului uman?\n",
            "Cum se mai numesc leococitele?\n",
            "Cate perechi de coaste au oamenii?\n",
            "Cate camere are inima?\n",
            "Cea mai mare artera din corpul uman?\n",
            "Cati dinti are un om matur?\n",
            "Cate oase are omul matura?\n",
            "Cate cromozomi are omul?\n",
            "Cate perechi de nervi poseda un om?\n",
            "Cate oase se gasesc in cutia toracica?\n",
            "Cel mai mic os la om?\n",
            "Cate oase se gasesc in cap?\n",
            "Cate procente din corpul uman al constituie apa?\n",
            "Care este cel mai lung intestin din corpul uman?\n",
            "Ce culoare are sangele?\n",
        },//tema 5
        {
            "Cand a fost primul razboi?\n",
            "Cand a fost al doilea razboi mondial?\n",
            "Anii de domnie a lui Stefan cel Mare?\n",
            "In ce tara a condus Hitler\n",
            "Primul domnitor a Moldovei?\n",
            "Ce tara a provocat al doilea razboi mondial?\n",
            "In ce tara domina fascismul?\n",
            "Anii de conducere a lui Stalin?\n",
            "Cine a solutionat Marea Criza mondiala?\n",
            "In ce tara a fost democratie in timpul celui dea doilea razboi mondial?\n",
            "In ce tara era promovata regimul totalitar?\n",
            "Cand Moldova a fost declarata independenta?\n",
            "In ce an s-a produs Marsul spre Roma?\n",
            "Cand s-a inceput Razboiul Rece?\n",
            "Cand s-a destramat URSS?\n"
        }
    };
    char a[15][15][4][1000] =
    {
        //tema 1
        {

            {
                "Italia",
                "Canada",
                "Rusia",
                "Moldova"//1
            },
            {
                "Roma",
                "Chisinau",//1
                "Moscova",
                "Berlin"
            },
            {
                "Rezina",
                "Orhei",
                "Balti",
                "Chisinau"//1
            },
            {
                "Igor Dodon",
                "Renato Usatii",
                "Maia Sandu",//1
                "Ursu Ionel"
            },
            {
                "Chisinau",//1
                "Orhei",
                "Bender",
                "Balti"
            },
            {
                "Stefan cel Mare",//1
                "Dacia",
                "Albisoara",
                "Hristo-Botev"
            },
            {
                "Independentei",
                "Dacia",
                "Muncesti",//1
                "Ion Creanga"
            },
            {
                "3 000 000",
                "2 640 438",//1
                "2 000 316",
                "2 200 214"
            },
            {
                "Buiucani",
                "Centru",
                "Botanica",//1
                "Ciocana"
            },
            {
                "821 231",
                "639 100",//adevarat
                "532 452",
                "934 221"
            },
            {
                "Germania",
                "Italia",
                "Romania",//1
                "Ucraina"
            },
            {
                "43 819 km^2",
                "33 846 km^2",//1
                "39 324 km^2",
                "40 314 km^2"
            },
            {
                "Iarna",
                "Toamna",
                "Primavara",
                "Toate"//1
            },
            {
                "Podis si campii",//1
                "Podis",
                "Campie",
                "Vulcanic"
            },
            {
                "Cernoziom",//1
                "Brune",
                "Cenusii",
                "Rosii"
            }

        },
        //tema 2
        {
            {
                "Tigru",
                "Veverita",
                "Ghepardul",//1
                "Zebra"
            },
            {
                "Iepurele de munte",
                "Soarecele de campie",
                "Hameleonul Brookesia Micra",//1
                "Broasca Areto Buni"
            },
            {
                "Calul",
                "Elefantul african",//1
                "Girafa",
                "Hipopotamul"
            },
            {
                "Balena albastra",//1
                "Elefantul",
                "Vaca",
                "Taurul"
            },
            {
                "Cainele",
                "Viespea de mare",//1
                "Albina",
                "Sarpele"
            },
            {
                "Tigrul",
                "Zebra",
                "Pisica",//1
                "Ursul"
            },
            {
                "Iepurele",
                "Porcul",
                "Vaca",
                "Lupul"//1
            },
            {
                "Iepurele",
                "Cainele",
                "Tigrul",//1
                "Porcul"
            },
            {
                "Balena albastra",//1
                "Rechinul",
                "Meduza",
                "Delfinul"
            },
            {
                "Vaca",
                "Iepurele",
                "Lupul",//1
                "Capra"
            },
            {
                "Iepurele",//1
                "Tigrul",
                "Lupul",
                "Leul",
            },
            {
                "Zebra",
                "Cainele",//1
                "Calul",
                "Capra"
            },
            {
                "Broasca",//1
                "Capra",
                "Iepurele",
                "Omul"
            },
            {
                "1 zi",
                "1 ora",
                "2 zile",
                "2 saptamani"//1
            },
            {
                "Moldova",
                "Africa",
                "Madagascar",//1
                "Italia"
            }
        },//tema 3
        {

            {
                "Troposfera"//1,
                "Scoarta",
                "Mantaua",
                "Nucleu"
            },
            {
                "America",
                "Antartica",//1
                "Africa",
                "Asia"
            },
            {
                "Mantaua",
                "Scoarta",
                "Nici una",
                "Nucleul"//1
            },
            {
                "America",
                "Antartica",
                "Asia",//1
                "Africa"
            },
            {
                "Biosfera",//1
                "Mezosfera",
                "Troposfera",
                "Litosfera"
            },
            {
                "3",//1
                "2",
                "7",
                "5"
            },
            {
                "Jupiter",
                "Pamant",
                "Pluton",//1
                "Venus"
            },
            {
                "Pamanat",
                "Mercur",//1
                "Saturn",
                "Uranus"
            },
            {
                "Jupiter",
                "Venus",
                "Marte",//1
                "Mercur"
            },
            {
                "Planeta",
                "Stea",//adevarat
                "Satelit",
                "Asteroid"
            },
            {
                "30%",
                "90%",
                "71%",//1
                "10%"
            },
            {
                "Soarele",
                "Luna",//1
                "Luceafarul",
                "Sputnik"
            },
            {
                "Pamant",
                "Venus",
                "Jupiter",
                "Marte"//1
            },
            {
                "Intenstinul subtire",//1
                "Intenstinul gros",
                "Ambele au acceasi lungime",
                "-"
            },
            {
                "rosu",//1
                "verde",
                "albastru",
                "negru"
            }

        },
        //tema 4
        {
            {
                "Omoplat",
                "Sternul",
                "Femurul",//1
                "Coccisul"
            },
            {
                "Globule rosii",
                "Globule albe",
                "Limfa",//1
                "Sange"
            },
            {
                "10",
                "12",//1
                "14",
                "8"
            },
            {
                "4",//1
                "3",
                "2",
                "5"
            },
            {
                "Pulmonara",
                "Aorta",//1
                "Cava",
                "Nici una"
            },
            {
                "30",
                "34",
                "32",//1
                "28"
            },
            {
                "201",
                "250",
                "270",
                "206"//1
            },
            {
                "50",
                "47",
                "46",//1
                "44"
            },
            {
                "12",//1
                "13",
                "10",
                "14"
            },
            {
                "22",
                "21",
                "25",//1
                "20"
            },
            {
                "Scarita",//1
                "Ciocan",
                "Nicovala",
                "Hioid",
            },
            {
                "20",
                "29",//1
                "10",
                "30"
            },
            {
                "60",//1
                "99",
                "50",
                "32"
            },
            {
                "1 zi",
                "1 ora",
                "2 zile",
                "2 saptamani"//1
            },
            {
                "Moldova",
                "Africa",
                "Madagascar",//1
                "Italia"
            }
        },//tema 5
        {

            {
                "1911-1912",
                "1913-1915",
                "1900-1910",
                "1914-1918"//1
            },
            {
                "1930-1931",
                "1939-1945",//1
                "1940-1940",
                "1931-1946"
            },
            {
                "1359-1401",
                "1430-1450",
                "1360-1390",
                "1457-1504"//1
            },
            {
                "Romania",
                "Marea Britanie",
                "Germania",//1
                "Italia"
            },
            {
                "Dragos I",//1
                "Bogdan I",
                "Stefan I",
                "Pentru I"
            },
            {
                "Germania",//1
                "URSS",
                "Anglia",
                "Franta"
            },
            {
                "Romania",
                "Basarabia",
                "Italia",//1
                "Franta"
            },
            {
                "1920-1940",
                "1925-1953",//1
                "1919-1920",
                "1930-1953"
            },
            {
                "Hitler",
                "Stalin",
                "Franklin Rossvelt",//1
                "Stefan Stratulat"
            },
            {
                "Romania",
                "SUA",//adevarat
                "URSS",
                "Germania"
            },
            {
                "Marea Britanie",
                "SUA",
                "Germania",//1
                "Franta"
            },
            {
                "1950",
                "1991",//1
                "1978",
                "1995"
            },
            {
                "1930",
                "1940",
                "1925",
                "1922"//1
            },
            {
                "1947",//1
                "1946",
                "1960",
                "1940"
            },
            {
                "1991",//1
                "1994",
                "1990",
                "1992"
            }

        }
    };

    char true_a[15][15][4] =
    {
        {
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            }
        },//tema 2
        {
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            }
        },
         {
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            }
        },//tema 2
        {
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            }
        },
        {
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                0,
                0,
                1,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                1,
                0
            },
            {
                0,
                1,
                0,
                0
            },
            {
                0,
                0,
                0,
                1
            },
            {
                1,
                0,
                0,
                0
            },
            {
                1,
                0,
                0,
                0
            }
        }
    };
    int n=5;
    int n_q =15;
    int n_a=4;
    int count=0,x=0;

    while(count <= 15)
    {
        int theme_n=rand()%n;
        int q_n = rand()%n_q;
        printf("\nTema este : %s\n",teme[theme_n]);
        printf("\nIntrebarea este: %s\n", q[theme_n][q_n]);
        printf("\nVariante de raspuns:\n");
        for(int i=0; i<n_a; i++)
        {
            printf("%d) %s\n", i,a[theme_n][q_n][i]);
        }
        printf("\nIntroduceti numarul raspunsului\n");
        int nr;
        scanf("%d",&nr);
        if(true_a[theme_n][q_n][nr])
        {
            printf("\nAti raspuns corect\n");
            x++;
            if(x==10)
            {
                printf("\n\n\n");
                printf("URAAAAAAAAAAA\n Ati castigat jocul\nFelicitari!!!!!!");
                printf("Ati raspuns corect la toate 10 intrebari corect\n");
                printf("Ati castigat un MILION!!!!!!\n");
                printf("\n\n\n");
                break;
            }
        }
        else
        {
            printf("\nDin pacare ati raspuns gresit.Ati pierdut jocul\n");
            printf("Plecati acasa\n");
            break;
        }
    }
    return 0;
}
