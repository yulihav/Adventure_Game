#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Layout:
 *
 *                                 +------------+
 *                                 |            |
 *                                 |     11     |
 *                                 | Princess   |
 *                                 +----+  +----+
 *                                      |  |
 *                                 +----+  +----+
 *                                 |            |
 *                                 |     10     |
 *                                 |   Dragon   |
 *                                 +----+  +----+
 *                                      |  |
 *             +--------+ +------+ +----+  +----+ +---------+
 *             |        | |      | |            | |         |
 *             |   6    +-+  7   +-+      8     +-+   9     |
 *             | Sword                              Flowers |
 *             |        +-+      +-+            +-+         |
 *             |        | |      | |            | |         |
 *             +--------+ +------+ -----+  +----+ +---------+
 *                                      |  |
 *                 +--------+      +----+  +----+ +---------+
 *                 |        |      |            | |         |
 *                 |   3    +------+     4      +-+   5     |
 *                 |  Dark     2                    Broccoli |
 *                 |        +-+  +-+            +-+         |
 *                 |        | |  | |            | |         |
 *                 +--------+ |  | +------------+ +---------+
 *                            |  |
 *                            |  |
 *                             1
 *                            Cave
 */

#define DELAY 1

int delay = DELAY;
int location = 1;
int haveFlowers = 0;
int haveSword = 0;
int ateBroccoli = 0;
int dead = 0;
int killedSlug = 0;
int killedDragon = 0;
int savedPrincess = 0;
int coward = 0;
int action;

void doError()
{
    printf("What!?\n");
    sleep(delay);
}

int getAction()
{
    char  actionString[80];

    fgets(actionString, sizeof(actionString), stdin);
    return atoi(actionString);;
}

void doMove()
{
    printf(".");
    fflush(stdout);
    sleep(delay);
    printf(".");
    fflush(stdout);
    sleep(delay);
    printf(".");
    fflush(stdout);
    sleep(delay);
    printf("\n\n\n");
}

void doLocation1()
{
    printf("You see the entrance to a cave to the north.\n");
    printf("You hear a princess yelling, \"Help me!\"\n");
    printf("You also hear a loud roar.\n");
    printf("What do you do?\n");
    printf("1) Enter cave\n");
    printf("2) Run away\n");
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 2;
            break;
        case 2 :
            coward = 1;
            break;
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation2()
{
    printf("You are inside the cave. "
           "The smell of brimstone is overpowering.\n");
    printf("You see a hallway leading west, a hallway leading east,\n");
    printf("and a hallway leading south.\n");
    printf("What do you do?\n");
    printf("1) Go east\n");
    printf("2) Go west\n");
    printf("3) Go south\n");
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 4;
            break;
        case 2 :
            location = 3;
            break;
        case 3 :
            location = 1;
            break;
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation3()
{
    printf("It's really dark in here.\n");
    
    printf("You can't see a thing.\n");
    
    printf("You bumble around the room and finally find your way out.\n");
    location = 2;
    doMove();
}

void doLocation4()
{
    printf("You are standing in a room that is empty except for "
           "spider webs all over.\n");
    printf("There are hallways leading west, north, and east.\n");
    printf("What do you do?\n");
    printf("1) Go east\n");
    printf("2) Go north\n");
    printf("3) Go west\n");
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 5;
            break;
        case 2 :
            location = 8;
            break;
        case 3 :
            location = 2;
            break;
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation5()
{
    if (!ateBroccoli)
    {
        printf("You are in a room.\n");
        printf("You see a can of Broccoli.\n");
    }
    else
    {
        printf("You are in a room with an empty can of Broccoli.\n");
    }
    printf("There is a hallway to the west.\n");
    printf("What do you do?\n");
    printf("1) Go west\n");
    if (!ateBroccoli)
    {
        printf("2) Eat Broccoli\n");
    }
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 4;
            break;
        case 2 :
            if (!ateBroccoli)
            {
                printf("Yuck!\n");
                printf("You feel much stronger\n");
                ateBroccoli = 1;
                break;
            }
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation6()
{
    if (!haveSword)
    {
        printf("You are in a room.\n");
        printf("You see a sword lying on a large stone.\n");
    }
    else
    {
        printf("You are in a room with a large stone.\n");
    }
    printf("There is a hallway to the east.\n");
    printf("What do you do?\n");
    printf("1) Go east\n");
    if (!haveSword)
    {
        printf("2) Take sword\n");
    }
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 7;
            break;
        case 2 :
            if (!haveSword)
            {
                printf("You take the sword.\n");
                haveSword = 1;
                break;
            }
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation7()
{
    if (!killedSlug)
    {
        printf("You are in a room.\n");
        printf("On the ground, you see a disgusting slug.\n");
        printf("What do you do?\n");
        printf("1) Run away like a little girl\n");
        printf("2) Step on slug\n");
        printf("? ");
        action = getAction();
        switch (action)
        {
            case 1 :
                printf("You shriek and run away.\n");
                printf("You hear the princess yell out,\n");
                printf("\"Do I have to save myself!?\"\n");
                location = 8;
                break;
            case 2 :
                printf("You get slug slime on your boots\n");
                printf("as you squish the slug.\n");
                killedSlug = 1;
                break;
           default :
                doError();
                break;
        }
    }
    else
    {
        printf("You are in a room with slug guts on the floor.\n");
        printf("There is a hallway to the west and to the east.\n");
        printf("What do you do?\n");
        printf("1) Go west\n");
        printf("2) Go east\n");
        printf("? ");
        action = getAction();
        switch (action)
        {
            case 1 :
                location = 6;
                break;
            case 2 :
                location = 8;
                break;
            default :
                doError();
                break;
        }
    }
    doMove();
}

void doLocation8()
{
    printf("You are in an empty room. It is very warm in here.\n");
    printf("There is a hallway to the west, north, east, and south.\n");
    printf("What do you do?\n");
    printf("1) Go west\n");
    printf("2) Go north\n");
    printf("3) Go east\n");
    printf("4) Go south\n");
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 7;
            break;
        case 2 :
            location = 10;
            break;
        case 3 :
            location = 9;
            break;
        case 4 :
            location = 4;
            break;
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation9()
{
    if (!haveFlowers)
    {
        printf("You are in a room.\n");
        printf("On the ground, you see some flowers growing.\n");
    }
    else
    {
        printf("You are in a room. You see a patch of dirt where "
               "flowers once grew.\n");
    }
    printf("There is a hallway to the west.\n");
    printf("What do you do?\n");
    printf("1) Go west\n");
    if (!haveFlowers)
    {
        printf("2) Pick flowers\n");
    }
    printf("? ");
    action = getAction();
    switch (action)
    {
        case 1 :
            location = 8;
            break;
        case 2 :
            if (!haveFlowers)
            {
                printf("You pick the flowers.\n");
                printf("They smell lovely.\n");
                haveFlowers = 1;
                break;
            }
        default :
            doError();
            break;
    }
    doMove();
}

void doLocation10()
{
    if (!killedDragon)
    {
        printf("You are in a room.\n");
        
        printf("You see a blood thirsty dragon!!!\n");
        
        printf("You wet your pants a little.\n");
        
        printf("What do you do?\n");
        printf("1) Run away\n");
        printf("2) Fight dragon\n");
        printf("? ");
        action = getAction();
        switch (action)
        {
            case 1 :
                printf("You run away screaming.\n");
                printf("You hear the princess call out,\n");
                printf("\"What a wuss!\"\n");
                location = 8;
                break;
            case 2 :
                if (!haveSword)
                {
                    printf("You lunge at the dragon.\n");
                    
                    printf("He giggles as you desperately claw at him\n");
                    printf("with your bare hands.\n");
                    
                    printf("He then eats you in one bite.\n");
                    
                    printf("You're dead.\n");
                    dead = 1;
                }
                else if (!ateBroccoli)
                {
                    printf("You lunge at the dragon swinging your sword.\n");
                    
                    printf("You don't have the strength to pierce his scales\n"
                           "(you didn't eat broccoli).\n");
                    
                    printf("The dragon breathes fire and "
                           "burns you to a crisp.\n");
                    
                    printf("You're dead.\n");
                    dead = 1;
                }
                else
                {
                    printf("You lunge at the dragon swinging your sword.\n");
                    
                    printf("You drive your sword deep into "
                           "the dragon's heart.\n");
                    
                    printf("The dragon gasps his last breath...\n");
                    
                    printf("and falls down dead.\n");
                    
                    killedDragon = 1;
                }
                break;
            default :
                doError();
                break;
        }
    }
    else
    {
        printf("You are in a room with the skeleton of a dead dragon.\n");
        printf("There is a hallway to the south and north.\n");
        printf("What do you do?\n");
        printf("1) Go north\n");
        printf("2) Go south\n");
        printf("? ");
        action = getAction();
        switch (action)
        {
            case 1 :
                location = 11;
                break;
            case 2 :
                location = 8;
                break;
            default :
                doError();
                break;
        }
    }
    doMove();
}

void doLocation11()
{
    if (!haveFlowers)
    {
        printf("You enter a room.\n");
        
        printf("You see the most beautiful woman ever!\n");
        
        printf("She looks upset.\n");
        
        printf("What!? No flowers!?\n");
        
        printf("She furiously pushes you out of the room.\n");
        location = 10;
    }
    else
    {
        printf("You enter a room.\n");
        
        printf("You see the most beautiful woman you have ever seen!\n");
        
        printf("She runs toward you with her arms open.\n");
        
        printf("She says, \"My hero!!!\"\n");
        
        printf("\"What lovely flowers!\"\n");
        
        printf("\"Rescue me now!!\"\n");
        savedPrincess = 1;
    }
    doMove();
}

int main()
{
    printf("The king calls out to all knights of the land.\n");
    
    printf("The princess has been kidnapped by an evil dragon.\n");
    
    printf("The king promises the princess's hand in marriage to anyone "
           "who can save her.\n");
    
    printf("You bravely accept his offer and head out into the dark forest.\n");
    doMove();

    while (!dead && !savedPrincess && !coward)
    {
        switch (location)
        {
            case 1:
                doLocation1();
                break;
            case 2:
                doLocation2();
                break;
            case 3:
                doLocation3();
                break;
            case 4:
                doLocation4();
                break;
            case 5:
                doLocation5();
                break;
            case 6:
                doLocation6();
                break;
            case 7:
                doLocation7();
                break;
            case 8:
                doLocation8();
                break;
            case 9:
                doLocation9();
                break;
            case 10:
                doLocation10();
                break;
            case 11:
                doLocation11();
                break;
        }
    }

    if (savedPrincess)
    {
        printf("You have saved the princess.\n");
        
        printf("You marry her and live happily ever after.\n");
        
    }
    else if (dead)
    {
        printf("You have died.\n");
        
        printf("For your bravery, the king erects a statue.\n");
        
    }
    else if (coward)
    {
        printf("You run away like a coward.\n");
        
        printf("As you run, you hear the sound of a dragon "
               "munching on the princess.\n");
        
        printf("For your cowardice, the king arrests you \n");
        
        printf("and you spend the rest of your life in the dungeon.\n");
    }
}
