#include <stdio.h>
#include <string.h>

int main()
{
    // a new version, we'll be using fgets() instead of scanf() now. i see that it is dangerous...
    int monster_alpha;
    int player_health;
    int punch_attack_power;
    char character_name[255]; // SHIIIT IF I DO NOT PROVIDE A VALUE IT'LL NEVER BE BUFFER OVERRUN FUCK YEAAH
    // never mind.. i have to provide a value for single-dimensional arrays. OR I COULD JUST = TO FGETS... nah not gonna happen :/
    char special_character[1] = "[";
    // eh fuck it I'll just use an integer variable to define true or false values. 0-false, 1-true.
    int goblin_is_defeated = 0;
    int isInvalidInput = 1; // this variable is to detect whether or not the user entered a correct value, it'll turn into a 0 and be considered false, and end the loop and continue off of that IF/ELSE block.
    monster_alpha = 15;
    player_health = 200;
    punch_attack_power = 5;

    printf("Welcome to the alpha version of <insert game name here>.\nCOPYRIGHT u/Bahrican798.\n");
    printf("I know, it's not much, obviously. This is as much as I can get done in this environment...\n");
    char user_input[255];
    printf("===================================================\n");
    printf("\t\t TYPE \"Start\" TO PLAY\t\t\t\n");
    printf("===================================================\n");
    do
    {
        printf(">||: ");
        fgets(user_input,255,stdin);    // try fgets maybe... I'm tired. the if statements dont work... skips directly to else and returns 2.
        user_input[strcspn(user_input, "\n")] = 0;
        //printf("%s",user_input); okay fgets works fine... although strcmp is not happy with how I compare strings now that I use fgets it seems.
        // printf("you wrote: %s", user_input); // although when checked in with printf, it seems that scanf reads everything, not just the first character only... I guess it does not store it as a variable then?
        // FIXED IT :D the "\n" is important in fgets apparently, never forget that!!! never forget the \n!!! hold the fuck up something's wrong here... the ".n" is printed onto a newline? this shit could prove to be a problem in the future, better solve it now. Alright it's fixed! learned how to get rid of the attached newline on the string!
        if(strcmp(user_input, "Start") == 0) // FUCK YES FINALLY IT CAN START
        {
            isInvalidInput = 0; // do-while condition is set to false, hence ending the loop and achieving what we did with goto. no more spaghetti code that's hard to track, yaaay!!.. it's fucking, what, 2am? im tired..
            // phew... almost lost all progress there, LiveOSes are a dangerous environment to do development on!
            printf("Choose your name, choose wisely for it can NOT be changed later on! Max. 255 characters: ");
            fgets(character_name,255,stdin); // why does fgets not work? does it have something to do with the loop? the if statement bothers it maybe? fuck im tired
            // yeah replaced the scanf here and everywhere else with fgets, I have seen that it crashes if the user inputs an overflowing value.. and there is nothing to stop the user from doing that :P
            character_name[strcspn(character_name, "\n")] = 0;
            printf("Your name is %s.n", character_name);
            printf("Welcome... to a new world.\n");
            printf("You're wondering around.\n");
            printf("You keep walking for hours on end.\n");
            printf("It's getting late...\n");
            printf("You stumble upon a little cave. Go inside? Y/n >||: ");
            // I need to find a way to print [], (), {}....
             // well making a string variable and putting '[' in it and printing it via printf %s IS an option... but not efficient. There MUST be a way to just print those characters without a hassle!
             // I gotta get some work done on this...
             // I better put it into the "to be done" section, I usually don't read comments.
            fgets(user_input,255,stdin);
            user_input[strcspn(user_input, "\n")] = 0;
            //printf("%s.n", user_input);
            // okay we either use fgets and chop off the attached newline each time, which is a bother, or just include in the newline when comparing strings and only chop off the newline when needed to which'll result in fewer lines of code. latter sounds better, right?
            if (strcmp(user_input, "Y") == 0 || user_input[0] == '\0') // fuck how do I detect if the user just pressed enter, do I just not let them?
            {
                printf("debug is working fine\n");

            }
            return 0;
        }

        else if (strcmp(user_input, "easter") == 0) // Fuck man I can't put in spaces there... I'll figure that out later, I need to make a release now
        {
            isInvalidInput = 0; // sets the do-while condition to false, ending the loop
            printf("Welcome to the pre-alpha release. This command is only known by those who observe the source code :D\n"); // Fuck I can't make a smiley ( ;) )
            printf("To do stuff:\n");
            printf("Ideas to be added:\n");
            printf("- Different routes.\n");
            printf("-Shops, alongside routes.\n");
            printf("-Show the user their options, how many paths they can take at that moment, what's nearby etc.\n");
            printf("-Experience points, leveling up and having your stats go up etc. Maybe I'll add the option to select which stat you wanna upgrade, like in Paper Mario\n");
            printf("-Small creatures on the road, and the option to fight them or leave them alone. I'll try to use boolean to determine if they are defeated or not, which then will block the user from killing the same creature again and again for free EXP and HP. Now that I mention this.. a new idea popped in, check the next one for it.\n");
            printf("-Be able to go back the routes you take... I'm not sure how I'll do that, I'll figure it out. But not today.\n");
            printf("-Earn money, exp etc. from killed creatures.\n");
            printf("-Have a stamina that increases on a timer. I don't know how I'll implement that in a console game, I'll keep reading the book to see if there is something like waiting a few seconds, otherwise I'll set up a loop with while or for, and calculate the time that passes by, and increase the stamina variable that way.\n");
            printf("-Be able to learn new abilites.. Reminds me of M&L: Superstar Saga\n");
            printf("-Settings? Maybe? what would one want to change in this \"game\" anyway\n");
            printf("-The player will be able to see how much exp left to level up... I'm still considering this, it's possible but why should I let them?\n");
            printf("-Adventure/Story Mode, Free fighting mode. The free fighting will only allow you to battle with monster you've fought before. To determine that, I'll use boolean again... Damn I'm getting too dependent on boolean, and it doesn't even exist in C.\n");
            printf("-Give the user a limited amount of health potions to begin with.\n");
            printf("-Stats, probably. This one didn't go well apparently in C#. I'll attempt it here, what could go wrong? Let the user see their stats, health, exp, level etc.\n");
            printf("-Setting max values for stuff like player_health, if it exceeds it's max value, make it equal to it's max value again. Perhaps I'll use a separate, untouched variable for this called 'max_health'.\n");
            printf("-A start menu wouldn't be so bad, like the ncurses menus in shell scripts!\n");
            printf("-Let the user choose their character's name.\n");
            printf("-Send the user back to the prompt if they input something not related or whatever.\n");
            printf("-Add an option to save the game... I don't know how to do that, I'll do it but not today.\n");
            printf("- Make a function in a separate file, prototype this first in Python though. Some sort of a loop, a while loop, that'll take different values like how for or printf does. This loop will be used for fights. It'll be a barebones function, we'll fill in the blanks--- string to print out like 'You defeated the boss!', 'You used punch, you did 20 damage'--- ourselves.\n");
            printf("-Randomize monsters' attacks. They'll have various attacks that do different amounts of damage. Use a random number generator or something ;_;\n");
            printf("Find a way to printf the following character, it's in the source code. Here I'll even print it here, BUT this is a troublesome way to print out a '%s'.\n", special_character);
            //printf("- DONT use goto! Apparently it's bad practice... find an alternative. Should be worth it, especially when you look at the old CS source code.. Damn that sure was one helluva spaghetti code.\n");
            printf("-Give the user a limited inventory, like in uhh.. umm.... i dont fucking remember the game name just give the user a small inventory and items around them to pick up/drop.\n");
            printf("-Either use command line options like --start, --debug and whatever, or use an in-game prompt like we are now. u/Urthemando_Mod looks like he is thirsty for cli options, so...\n");
            printf("-Perhaps make the variables an array? IF we ever add difficulty options to this, that could be useful to load in different values, e.g 10 damage for a monster in easy mode, 15 in normal, 20 in expert, 300/200/150 player health etc.\n");
            //printf("-Check fgets, scanf seems to be a pain...\n");
            printf("Added/fixed stuff:\n");
            printf("+Finally stopped using goto, I am using for loops instead now that for stopped being such a dick and started working...\n");
            printf("+Got rid of scanf, using fgets now.\n");
            printf("This is all for now I guess. New ideas come by every now and then, which I'll note down here in this 'Easter Egg' :P.\n");
            return 1;

        }
        else if(strcmp(user_input, "test") == 0)
        {
            isInvalidInput = 0; // ends the do-while loop by setting the loop condition to false
            for( ; monster_alpha > 0;) // I FUCKING HATE THE FOR STATEMENT IN C WHY DO I HAVE TO "iNItiaLiZE" SHIT I JUST WANNA GIVE A SINGLE CONDITION AND BE FUCKING DONE WITH IT
            // Oh nevermind ._. apparently I can just put in a semicolon and fuck off with it... why didn't work the first time I tried it though? I did the exact same thing..
            // this is pain
            // hold on, just a few more lines and we can release the pre-alpha version
            // alpha-release note, I could potentially replace this for loop with a do-while loop. i dont know which is more efficient...
            // do-while seems more explanotary, i mean i had a fucking heart-stroke while trying to understand this loop i wrote..
            {
                printf("test: ");
                scanf("%s", user_input);
                if(strcmp(user_input, "1") == 0)
                {
                    monster_alpha = monster_alpha - punch_attack_power;
                    printf("%d\t%d", monster_alpha, punch_attack_power);

                }

            }

            // Here's an idea.. don't erase the stuff you put in this chunk of code. Instead just comment them out, or put in goto statements and special commands which'll allow you to jump among testing grounds
        }
        else
        {
            printf("Please type \"Start\" to play.\n");
            //printf("I couldn't write something to send the user back to the prompt, sorry.."); // Well I COULD use goto... but this thing is about to evolve into a few thousand lines of code, doesn't feel right to use goto
            //^ NOT TRUE ANYMORE!! Finally figured out how to set up that do-while loop!! :DD so happy... wonder if u/Urthemando_Mod will be pleased with this "progress"... probs not, still. i finally got rid of the burden that is goto.
        }
    } while(isInvalidInput);
    return 0;

}
