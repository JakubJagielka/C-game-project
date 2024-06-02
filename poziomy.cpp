#include <iostream>
#include <conio.h> 
#include "header.h"

using namespace std;

void Game::Poziom_1() {
    cout << "Twoj bohater to " << bohater1.imie << " o parametrach: \nHP: " << bohater1.hp << "\nAtak: " << bohater1.atak << "\nObrona: " << bohater1.obrona << "\nPoziom: " << bohater1.poziom << "\nDoswiadczenie: " << bohater1.doswiadczenie << "\n" << endl;

    cin.ignore();
    system("cls");
    cout << "Gra rozgrywa sie we wspolczesnym swiecie, gdzie miasta i miasteczka funkcjonuja podobnie do naszych, z jedna znaczaca roznica: smoki istnieja. Te smoki nie sa zyczliwymi istotami z mitow; sa psotne i czesto zlowrogie, lubiace podpalac krajobrazy, budynki i domy. Jestes czescia elitarnej grupy strazakow znanej jako Brygada Skrzydla Ognia, ktora specjalizuje sie w zwalczaniu pozarow wywolanych przez smoki i ochronie ludnosci.\n" << endl;

    cin.ignore();

    cout << "Znajdujesz sie w tetniacym zyciem miescie Pyroklas, znanym z czestych obserwacji smokow i wynikajacych z tego pozarow. Ostatnio ataki smokow staly sie czestsze i intensywniejsze, co sugeruje zlowieszcze motywy stojace za ich dzialaniami. Brygada Skrzydla Ognia zrekrutowala ciebie, nowego, ale obiecujacego strazaka, aby pomogl stawic czola temu zagrozeniu.\n" << endl;

    cin.ignore();

    cout << "Wchodzisz do siedziby Brygady Skrzydla Ognia, gdzie zostajesz przywitany przez dowodce brygady, kapitana Aarona. Kapitan Aaron wyjasnia, ze jestes czescia zespolu, ktory ma za zadanie ochrone miasta Pyroklas przed smokami\n" << endl;

    cin.ignore();

    cout << "Twoja misja polega na udzieleniu pomocy pobliskiej wiosce, ktora jest atakowana przez smoka. Musisz stawic czola smokowi i ochronic wioske przed zniszczeniem. Kapitan wyslal juz tam swojego najlepszego strazaka, Mamona, ale nie ma od niego zadnych wiesci. Kapitan Aaron prosi cie, abys udal sie do wioski i dowiedzial sie, co sie stalo z Mammonem i jak mozesz pomoc w walce ze smokiem.\n" << endl;

    cout << "Co robisz?\n1. Wyrusz na misje\n2. Zapytaj kapitana Aarona o wiecej informacji" << endl;

    int wybor;
    cin >> wybor;

    if (wybor == 2) {
        cout << "Kapitan Aaron wyjasnia, ze smok, ktory podpala domy, to smok o imieniu Pyrodrak. Pyrodrak jest jednym z najbardziej zlosliwych smokow w okolicy i zawsze podpala domy w nocy, aby uniknac zauwazenia. Kapitan Aaron ostrzega cie, ze Pyrodrak jest bardzo niebezpieczny i musisz zachowac ostroznosc podczas walki z nim.\n" << endl;
    }
    bohater1.gold += 30;
    bool continueMission = true;
    while(continueMission){
    cout << "Wyruszasz na misje, dostales 30 sztuk zlota na zakupy przed wyprawa\n" << endl;
    
    cout << "Masz teraz " << bohater1.gold << " zlota" << endl;
    cout << "Gdzie chcesz sie udac?\n1. Zbrojmistrz\n2. Tawerna\n3. Wyrusz na misje." << endl;
    int wybor2;
    cin >> wybor2;

    if (wybor2 == 1) {
        loc1.zbrojmistrz.Wizyta(bohater1);
    } else if (wybor2 == 2) {
        loc1.tawerna.Wizyta(bohater1);
    } else if (wybor2 == 3) {
        cout << "Wyruszasz na misje" << endl;
        continueMission = false;
    } else {
        cout << "Nie ma takiej opcji" << endl;
        
    }
    }

    cout << "Nie ma juz odwrotu, wyruszasz na misje" << endl;
    string odp;
    cout<<"Zblizajac sie do bram miasta spotykasz malego chlopca, co mu powiesz?"<<endl;
    cin>>odp;
    cout<<"Chlopiec patrzy na ciebie z zdziwieiniem, po czym ucieka"<<endl;
    cin.ignore();
    cout << "Tak zaczyna sie twoja przygoda.\n"<<bohater1.imie <<"  Czy uratujesz setki bezbronnych ludz? Czy przezyjesz ta wyprawe?\nTo sie okaze, a hoj przygodo."<< endl;

    cin.ignore();
    system("cls");
    cout<<"Wychodzisz z miasta, podazasz dorga wsakzana przez kapitana, po kilku godzinach marszu docierasz do wioski, z daleka widzisz dym, postanawiasz przyspieszyc kroku"<<endl;
    cin.ignore();
    cout<<"W drodze do wsioki spotykasz grupke ludzi, wygladaja na przestraszonych, podchodizsz do nich"<<endl;
    string dilaog1[6] = {"Witajcie, przyslal mnie kapitan Aaron, co sie tu dzieje?", "Uciekaj, smok napadl na wioske, nie ma juz ratunku", "Gdzie jest kapitan Mammon?", "Nie wiemy, ostatni raz widzielismy go w centrum wioski, uciekaj, zanim cie zlapie smok", "Dziekuje, musze isc, moze uda mi sie go znalezc", "Czekaj, wez to, bomba woda i mikstura zdrowia, moze ci sie przydac"};
    for(int i=0; i<6; i++){
        if(i%2==0){
            cout<<bohater1.imie<<" : "<<dilaog1[i]<<endl;
        }else{
            cout<<"Grupka przerazonych ludzi : "<<dilaog1[i]<<endl;
        }
        cin.ignore();
    }
    bohater1.ekwipunek.bomba += 1;
    bohater1.ekwipunek.miksturaleczaca += 1;
    bohater1.maxhp = bohater1.hp;
    cout<<"Wbiegasz do wioski, zaczynasz slyszec odglosy walki, w centrum wioski widzisz smoka, ktos probuje go zastraszyc"<<endl;
    cout<<"Co robisz?\n1. Odrazu decydujesz sie pomuc\n2.Starasz sie zajac wyzsza pozycje "<<endl;
    int wybor3;
    cin>>wybor3;
    if(wybor3==1){
        cout<<"Dolaczajac sie do walki widzisz ze walczy juz z nim kapitan Mammon, smok wydaje sie wygrywac"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"                 |WALKA|\n\n";
        oponent smok("Pyrodrak", 100, 20, 10);
        oponent Mammon("Mammon", 100, 15, 5);
        this->walka(bohater1, smok, &Mammon, nullptr);
    }else if(wybor3==2){
        cout<<"Udaje ci sie zajac wyzsza pozycje, widzisz ze smok jest zbyt zajety walka z kapitanem Mammonem, aby zauwazyc ciebie"<<endl;
        cout<<"Twoje ataki z wyzszej pozycji sa bardziej skuteczne "<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"                 |WALKA|\n\n";
        bohater1.atak += 5;
        oponent smok("Pyrodrak", 100, 20, 10);
        oponent Mammon("Mammon", 100, 15, 5);
        this->walka(bohater1, smok, &Mammon, nullptr);
}

    cout<<"\n\n\n\n\n\n";
    cout<<"Zdobyles:\n100 doswiadczenia\n20 zlota\nMiksture leczaca\nBombe wodna\n\n";
    bohater1.doswiadczenie += 100;
    bohater1.gold += 20;
    bohater1.ekwipunek.miksturaleczaca += 1;
    bohater1.ekwipunek.bomba += 1;
    bohater1.atak += 1;
    bohater1.obrona += 1;
    cout<<"LVL UP Twoje statystyki zostaly zwiekszone"<<endl;
    cin.ignore();

    cout<<"Po zaciętej walce smok lezy martwy na ziemi, biezesz gleboki oddech, wioska zostala uratowana"<<endl;
    cout<<"Kapitan Mammon podchodzi do ciebie"<<endl;

    string dilaog2[5] = {"Dziekuje ci, bez ciebie nie udalo by sie pokonac smoka", "Walka z takim sojusznikiem to czyszta przyjemnosc, przysyła mnie kapitan Aaron", "Ah ten stary dran wyslal mnie tu samego, dobrze ze zdazyles te smoki sa grozniejsze niz myslalem", "Powinnismy odpoczac, walka byla ciezka ale nie ostatnia, musimy sie przygotowac na kolejne", "Madrze mowisz, urzadzilem sobie kwaterke w tawernie, zapraszam."};

    for(int i=0; i<5; i++){
        if(i%2==0){
            cout<<bohater1.imie<<" : "<<dilaog2[i]<<endl;
        }else{
            cout<<"Kapitan Mammon : "<<dilaog2[i]<<endl;
        }
        cin.ignore();
    }
    cout<<"Wchodzisz do tawerny, jest ona niemal ze opuszczona i mocno zniszczona, czujesz zmeczenie po walce"<<endl;
    cout<<"W rogu widzisz ciche przestraszone dzieci dzieci, co zrobisz?"<<endl;
    cout<<"1. Daj im 10 zlota\n2. Ignoruj"<<endl;
    int wybor4;
    cin>>wybor4;
    if(wybor4==1){
        if(bohater1.gold>=10){
        cout<<"Dajesz dzieciom 10 zlota"<<endl;
        bohater1.gold -= 10;
        bohater1.szczescie += 5;
        cout<<"Ddzieci wygladaja na nieobecne, musialo spotkac je duzo nieszczescia, ale czujesz sie lepiej pomagajac im"<<endl;
        }else{
            cout<<"Nie masz wystarczajaco zlota"<<endl;
        }

        
    }else if(wybor4==2){
        cout<<"Ignorujesz dzieci, czujesz sie zle, ale nie bedziesz marnowac zlota na obcych"<<endl;
        bohater1.szczescie -= 5;
    }

    cout<<"Tawerna jest zasadniczo pusta, wszystcy mieszkancy uciekli, razem z Mamonem postanowiliscie polozyc sie na luzkach i odpoczac do jutra"<<endl;
    cin.ignore();
    cout<<"\n\n          Koniec pierwszego poziomu\n"<<endl;
    cin.ignore();
    system("cls");

}

void Game::Poziom_2() {
    cout << "           Poziom 2" << endl;
    bohater1.hp = bohater1.maxhp;
    cout<<"Czujesz sie wypoczyty, twoje zdrowie zostalo w pelni odnowione"<<endl;
    cout<<"Wstajesz i widzisz ze Mammon juz wstal, wyglada na zmartwionego"<<endl;
    cout<<"Postanawiasz prorzmawiac z nim"<<endl;
    string dialog [7] = {"Dzien dobry, jak sie czujesz po wczorajszej walce?", 
                         "Dziekuje, czuje sie dobrze, musze poinformowac cie o zaistnialej sytuacji, nie jest zbyt dobrze",
                         "Co sie stalo?", 
                         "Smoki zaczely atakowac coraz czesciej, a ostatnio zaczely atakowac w dzien, nasze zapasy sie kurcza, musimy powstrzymac je jak najszybciej",
                         "Rozumiem, masz jakis plan?", 
                         "Tak, mam, ale potrzebuje twojej pomocy, musieli bysmy wyruszyc jak naszybciej i udac sie do ich wladcy Zaru aby go pokonac, to jedyny sposob",
                         "Zgoda, zrobimy to razem"};

    for(int i=0; i<7; i++){
        if(i%2==0){
            cout<<bohater1.imie<<" : "<<dialog[i]<<endl;
        }else{
            cout<<"Kapitan Mammon : "<<dialog[i]<<endl;
        }
        cin.ignore();
    }

    cout<<"Wyruszacie na misje, waszym celem jest pokonanie Wladcy Zaru, smoka ktory rzadzi smokami w okolicy"<<endl;
    cout<<bohater1.imie<<" : Jak sie tam dostaniemy?"<<endl;
    cout<<"Mammon : Pierwsza przeszkoda bedzie las, druga zas gory, wtedy dojdziemy do wladcy Zaru"<<endl;
    cin.ignore();
    
    cout<<"Wybierasz droge przez las, jest to dluga droga ale bezpieczna"<<endl;
    cout<<"Podczas drogi spotykacie Wladce Lasu, stora bestie ktora zyje w lasach"<<endl;
    cin.ignore();
    cout<<"Co robisz?\n1. Zaatakuj go\n2. Sprobuj go przekonac"<<endl;
    int wybor2;
    cin>>wybor2;
    if(wybor2==1){
        cout<<"Zaatakowales bestie, jest silniejsza niz sie spodziewales"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"                 |WALKA|\n\n";
        oponent bestia("Wladca Lasu", 180, 20, 10);
        oponent Mammon("Mammon", 100, 15, 5);
        this->walka(bohater1, bestia, &Mammon, nullptr);
    }else if(wybor2==2){
        cout<<"Sprobujesz go przekonac, bestia wydaje sie byc zaskoczona twoim podejsciem"<<endl;
        cin.ignore();
        cout<<"Bestia : Co tu robisz czlowieku, nikt nie przeszedl przez moje lasy od lat"<<endl;
        cout<<"Mammon : Jestesmy w pospiechu, musimy pokonac Wladce Zaru, prosimy o pozwolenie na przejscie"<<endl;
        cout<<"Bestia : Wladca Zaru? To zly smok, zawsze chcialem go pokonac, zrobmy tak dam wam zagadke, jesli ja rozwiazecie to pozwole wam przejsc"<<endl;
        cin.ignore();
        cout<<"Bestia : Co to jest? Nie jest zywe, ale rosnie. Nie ma pluc, ale potrzebuje powietrza. Nie ma buzi, ale woda go zabija. Co to jest?"<<endl;
        cout<<"Co odpowiadasz?\n1. Ogien\n2. Drzewo\n3. Olowek\n4. Drozdze"<<endl;
        int wybor3;
        cin>>wybor3;
        if(wybor3==1){
            cout<<"Bestia : Dobrze, rozwiazales zagadke, mozesz przejsc"<<endl;
        }else{
            cout<<"Bestia : Zle, nie mozesz przejsc"<<endl;
            cout<<"Bestia atakuje"<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<"                 |WALKA|\n\n";
            oponent bestia("Wladca Lasu", 180, 20, 10);
            oponent Mammon("Mammon", 100, 15, 5);
            this->walka(bohater1, bestia, &Mammon, nullptr);
        }
    }

    cout<<"Przechodzisz przez las, wychodzisz na polane, widzisz gory w oddali"<<endl;
    cout<<"Wchodzisz w gory, jest tam zimno i surowo, widzisz ze Mammon zaczyna sie dlawic, nie jest z nim dobrze, ale postanawia kontynuowac wspinaczke"<<endl;
    cin.ignore();
    cout<<"Wchodzicie w gory, po kilku godzinach marszu jestescie na szczycie, widzisz smoka, ale nie jest to Wladca Zaru"<<endl;
    cout<<"Mammon : To smok o imieniu Gorycz, nie jest naszym wrogiem, ale tez nie jest naszym przyjacielem" <<endl;
    cin.ignore();

    bool MammonZostaje = true;


    

    cout<<"Sprobujesz go przekonac, smok wydaje sie byc zaskoczony twoim podejsciem"<<endl;
    cin.ignore();
    cout<<"Gorycz : Co tu robisz czlowieku, nikt nie przeszedl przez moje gory od lat"<<endl;
    cout<<bohater1.imie<<": Jestesmy w pospiechu, musimy pokonac Wladce Zaru, prosimy o pozwolenie na przejscie"<<endl;
    cout<<"Gorycz : Wladca Zaru? To zly smok, zawsze chcialem go pokonac, zrobmy tak zostaw tu swojego przyjaciela na moje pozarcie, a ja pozwole ci przejsc i pomoge ci z Wladca Zaru"<<endl;
    cout<<"Co robisz?\n1. Zostaw Mammona\n2. Nie zgadzam sie"<<endl;
    int wybor4;
    cin>>wybor4;
    if(wybor4==1){
        cout<<"Zostawiasz Mammona, widzisz jak Gorycz pozera go na twoich oczach"<<endl;
        cin.ignore();
        this->MamonZostaje = false;
    }else if(wybor4==2){
        cout<<"Nie zgadzasz sie zostawic Mammona, Gorycz atakuje"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"                 |WALKA|\n\n";
        oponent gorycz("Gorycz", 200, 25, 15);
        oponent Mammon("Mammon", 100, 15, 5);
        this->walka(bohater1, gorycz, &Mammon, nullptr);
        this->MamonZostaje = true;

    }
    

    cout << "Zdobywasz:\n200 doswiadczenia\n50 zlota\n" << endl;
    bohater1.doswiadczenie += 200;
    bohater1.gold += 50;
    bohater1.atak += 2;
    bohater1.obrona += 2;
    cout << "LVL UP! Twoje statystyki zostaly zwiekszone." << endl;
    cin.ignore();

    if(this->MamonZostaje == true){
      cout << "Po zaciętej walce smok lezy martwy na ziemi, bierzesz gleboki oddech. Wiesz, ze teraz musisz zmierzyc sie z Wladca Zaru." << endl;
      cout<<"Mammon : Musimy isc, nie mamy juz czasu, Wladca Zaru czeka"<<endl;
    }else if(this->MamonZostaje == false){
      cout << "Gorycz: Dziekuje ci, za to ze pozwoliles mi zjesc tego smiecia, pomoge ci w walce z Wladca Zaru gdy go spotkasz, podazaj dalej scieszka a zniejdizesz wioske w kturej mozesz opoczac"<<endl;
    }

    cout<<"Wchodzisz glebiej w gory, zauwazasz mala spalana wioske, postanawiasz sprawdzic co sie tam stalo"<<endl;
    cin.ignore();


    cout<<"Wchodzisz do wioski, nagle widzisz ze jeden z domuw swiezo plonie, widzisz ze ktos jest w srodku i wola o pomoc"<<endl;
    cout<<"Moglbys uzyc 2 bomb wodnych aby ugas pozar, moglbys tez sprubowawc po prostu uzyc gasnicy nie tracac przy tym nic co wybierasz?"<<endl;
    cout<<"1. Uzyj bomb wodnych\n2. Uzyj gasnicy"<<endl;
    int wybor5;
    cin>>wybor5;
    if(wybor5==1){
        cout<<"Uzywasz bomb wodnych, pozar zostaje ugaszony, w srodku domu znajdujesz starszego mezczyzne, ktory dziekuje ci za pomoc"<<endl;
        cout<<"Mezczyzna : Dziekuje ci, uratowales mi zycie, jestem tutejszymm kowalem, zostalem jako jedyn z wioski, reszta uciekla, przeosze spojrzyj na moje towary"<<endl;
        this->loc1.zbrojmistrz.Wizyta(bohater1);
    }else if(wybor5==2){
        cout<<"Uzywasz gasnicy, pozar zostaje ugaszony ale caly dom zostaje zniszczony, w srodku domu znajdujesz starszego mezczyzne, ktory dziekuje ci za pomoc"<<endl;
        cout<<"Mezczyzna : Dziekuje ci, uratowales mi zycie, jestem tutejszymm kowalem, niestety wszystko splocilo sie w popiol, nie moge ci nic zaoferowac"<<endl;
    }
    if(this->MamonZostaje == true){
      cout<<"Wraz z Mamonem postanawiacie odnowic sily w wiosce, nastepnego dnia wyruszacie na spotkanie z Wladca Zaru"<<endl;
    }else if(this->MamonZostaje == false){
        cout<<"Postanawiasz odpoczac w wiosce, nastepnego dnia wyruszasz na spotkanie z Wladca Zaru"<<endl;
    }


    cout << "\n\n          Koniec drugiego poziomu\n" << endl;
    cin.ignore();
    system("cls");

}

void Game::Poziom_3() {
    cout << "           Poziom 3" << endl;
    bohater1.hp = bohater1.maxhp;
    cout << "Odzyskujesz sily, twoje zdrowie zostalo w pelni odnowione" << endl;
    cout << "Ruszasz, zblizajac sie do legowiska Wladcy Zaru." << endl;
    cin.ignore();

    cout << "Po pokonaniu smoka straznika, zblizasz sie do legowiska Wladcy Zaru." << endl;
    cout << "Widok jest przerażający: ogromny smok o płonących oczach patrzy na ciebie. To Wladca Zaru, ostatnie wyzwanie." << endl;
    cin.ignore();
    
    cout << "Wladca Zaru : Witaj, czlowieku. Co cie tu sporwadza? Czy chcesz zginac?" << endl;
    cout << bohater1.imie << " : Jestem tutaj, aby pokonac ciebie i ocalic wioski, ktore zniszczyles." << endl;
    cin.ignore();
    cout << "Wladca Zaru : Haha, zniszczylem? A co z innymi zwierzetami kturym ludzie zniszczyli domy? Tak jak wy nie przyjmujecie sie mruwkami tak ja nie przyjmuje sie ludzmi." << endl;
    cout << bohater1.imie << " : Nie moge pozwolic na to, musze cie pokonac." << endl;
    cin.ignore();
    cout << "Wladca Zaru : Checie zdominowac smoki jak zdominowaliscie inne zwierzeta? I to ja jestem zly?" << endl;
    cout<<"Wladca Zaru wydaje sie chciec z toba rozmawiac, co robisz?\n1. Rozmawiaj z nim\n2. Zaczynaj walke"<<endl;
    int wybor;
    cin>>wybor;
    if(wybor==1){
        cout<<"Rozmawiasz z Wladca Zaru, wydaje sie byc zaskoczony twoim podejsciem"<<endl;
        cin.ignore();
        cout<<"Wladca Zaru : Chcesz mnie przekonac do zmiany? Marna proba, ale moze zasluzysz na moje wsparcie, jesli rozwiazesz zagadke"<<endl;
        cin.ignore();
        cout<<"Jestem siłą, która może cię wznieść wysoko, lecz także ściągnąć cię z nieba do otchłani, często pozostawiając pokorę poza zasięgiem wzroku. Możesz mnie uchwycić mocno, ale uważaj, bo w moim uścisku możesz zostać wchłonięty. Czym jestem?"<<endl;
        cout<<"Co odpowiadasz?\n1. Pycha\n2. Strach\n3. Ciekawosc\n4. Postrach"<<endl;
        int wybor2;
        cin>>wybor2;
        if(wybor2==1){
            cout<<"Wladca Zaru : Dobrze, rozwiazales zagadke, przyznales sie do swojej pychy, moze jestes godzien mojego wsparcia"<<endl;
            cout<<"Wladca Zaru : Nie bede juz atakowal ludzi, znikne wraz z moimi smokami, dziekuje ci za rozmowe"<<endl;
            cout<<"Zdobyles:\n300 doswiadczenia\n70 zlota\n" << endl;
            bohater1.doswiadczenie += 300;
            bohater1.gold += 70;
            bohater1.atak += 3;
            bohater1.obrona += 3;
            cout << "LVL UP! Twoje statystyki zostaly zwiekszone." << endl;
            cin.ignore();
        }else{
            cout<<"Wladca Zaru : Zle, nie zasluzyles na moje wsparcie, zginiesz"<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<"                 |WALKA|\n\n";
            if(this->MamonZostaje == true){
                cout<<"Mammon : Nie zostawie cie samego, pomoge ci"<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<"                 |WALKA|\n\n";
                oponent Mammon("Mammon", 100, 15, 5);    
                oponent WladcaZaru("Wladca Zaru", 500, 40, 30);
                this->walka(bohater1, WladcaZaru, &Mammon, nullptr);
        }

    }}else{
    
        

    cout << "                 |WALKA OSTATECZNA|\n\n";
    oponent wladcaZaru("Wladca Zaru", 500, 40, 30);
    this->walka(bohater1, wladcaZaru, nullptr, nullptr);

    cout << "Po epickiej walce, Wladca Zaru lezy martwy u twoich stop. Udalo ci sie! Zniszczyles zagrozenie i uratowales wioski." << endl;
    cout << "Zdobyles:\n500 doswiadczenia\n100 zlota\nLegendarny WasserShuriken\n" << endl;
    bohater1.doswiadczenie += 500;
    bohater1.gold += 100;
    bohater1.atak += 5;
    bohater1.obrona += 5;
    cout << "LVL UP Twoje statystyki zostaly znacznie zwiekszone." << endl;
    cin.ignore();}




    cout << "Wrociles do miejca Pyroklas jako bohater. Kapitan Aaron i reszta Brygady Skrzydla Ognia witaja cie jako mistrza smokow." << endl;
    cout << "\n\nGratulacje! Ukonczyles gre!\n" << endl;
    cin.ignore();
    system("cls");
}