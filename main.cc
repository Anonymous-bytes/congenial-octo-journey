# include <string.h>
# include <iostream>
# include <chrono>
# include <thread>

# define log(arg) std::cout<<arg<<std::flush

# define sleep(time) std::this_thread::sleep_for( \
                std::chrono::milliseconds(time) )


void load_scr(bool* con)
{
	for( auto i: (std::string) "loading ...")
        {
                log (i);
		sleep(100);
        }
	while ( *con )
        {
                log("\033[?25l");
                sleep(400);
                log("\033[?25h");
                sleep(400);
        }
        log (" --> done \n");
}

void process (bool *con)
{
        sleep(30000);
        *con = false;
}

int main(int argc,char** argv)
{
        bool condition = true;
        std::thread p1( &load_scr ,&condition );
        std::thread p2( &process ,&condition );
        p2.join();
        p1.join();

        return 0;
}
