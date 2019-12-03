!  Menu System for "Revenge"

[ HelpWhatSub;
  print "~Revenge~ is an adventure game which, I hope, is a little different
        to the ~get- sword-kill-troll~ stereotype.
        ^^
        The aim of the game is to do as much physical, psychological and
        monetary damage to your next-door neighbour as you can. Do not let
        morals, scruples or sensibilities interfere.  (Points can however be
        lost by unimaginative or plain sadistic acts of revenge.) It is
        important to remember that when committing an act of revenge, the
        enjoyment (and hence the points) is gained not from the setting of the
        trap, but from seeing it snare your victim.
        ^^
        There are three ways to complete ~Revenge~, and many different scores
        can be attained with each method of completion. The scores from acts
        of revenge which, when exacted, have a knock-on effect and cause
        another such act, can be multiplied together rather than being added,
        so think before you simply put a brick through a window.
        ^^
        What little violence occurs in ~Revenge~ is of the Tom and Jerry/Road
        Runner ~cartoon~ variety, and is not to be taken too seriously. As in
        any work of fiction, the author does not necessarily condone or
        approve of the acts contained within ~Revenge~, so please don't write
        me off as a malicious sadist.";
];

[ HelpLicenseSub;
  "~Revenge~ is freely distributable. Do what you want with it, just keep my
  name in the banner.";
];

[ HowToPlaySub;
  DoMenu("In the following page, words in bold face are commands which you
         can type.
         ^
         ^     Moving around the map
         ^     Manipulating objects
         ^     Interacting with other people
         ^     Special commands",
  HowToInfo, HowToMenu);
];

[ MovingAround;
  print "The maps of adventure games such as ~Revenge~ are broken down into
        small locations traditionally known as ~rooms~. These locations may
        not actually be rooms in the literal sense of the word, but perhaps a
        certain point along a road, a portion of a larger ballroom, or the
        inside of a car. You move from one room to another, perhaps through
        doors or in vehicles, by exploiting your unerring sense of direction
        and typing commands such as
        ^";
  style bold;
  print "^      GO NORTH
         ^      SOUTH
         ^      SOUTHEAST
         ^";
  style roman;
  print "^
         which can be abbreviated to
         ^";
  style bold;
  print "^      N
         ^      S
         ^      SE
         ^";
  style roman;
  print "^
        respectively. Additionally, by cunning use of ropes, ladders or stairs
        etc. you might be able to go
        ^";
  style bold;
  print "^      UP ";
  style roman;
  print "or
        ^";
  style bold;
  print "      DOWN";
  style roman;
  print "^
        (you could, of course, just type ";
  style bold;
  print "U";
  style roman;
  print " or ";
  style bold;
  print "D";
  style roman;
  print ")
        ^^
        You could also try to
        ^";
  style bold;
  print "^      CLIMB THE ROPE";
  style roman;
  print " or ";
  style bold;
  print "GO DOWN THE STAIRCASE";
  style roman;
  print ".^^
        Certain portals may also enable you to ";
  style bold;
  print "ENTER";
  style roman;
  print " a place, and, if you are lucky, ";
  style bold;
  print "EXIT";
  style roman;
  print " it again. (You can also use the commands ";
  style bold;
  print "IN";
  style roman;
  print " and ";
  style bold;
  print "OUT";
  style roman;
  print ".) If you keep a map of the game and know your way around, you might
        like to link a series of moves like so:^";
  style bold;
  print "^      E. NE. U. ENTER WENDY HOUSE. S. SW. GO THROUGH THE TIME
        VORTEX.
        ^";
  style roman;
];

[  ManipulatingObjects;
  print "The methods of communicating with adventure games haven't really
        changed over the last twenty years, although the classic ~verb noun~
        commands such as
        ^";
  style bold;
  print "^      GET SWORD
        ^      KILL TROLL
        ^";
  style roman;
  print "^
        are now supplemented by more complex instructions; so one might now^";
  style bold;
  print "^      TAKE THE SAMURAI SWORD FROM THE WALL
        ^";
  style roman;
  print "^
        and whilst the troll takes up his best fencing stance,
        ^";
  style bold;
  print "^      SHOOT THE TROLL WITH THE ARMY HOWITZER";
  style roman;
  print ".
        ^^
        Manipulation and interaction of objects along the lines of:
        ^";
  style bold;
  print "^      SMELL THE GLOVE
        ^      EXAMINE THE CROTCHLESS CATSUIT
        ^      LOOK UNDER THE BED
        ^      UNLOCK THE SECRET DOOR WITH THE SKELETON KEY
        ^      SEARCH THE DRAWER
        ^      PUT EVERYTHING EXCEPT THE BOOKS IN THE DUSTBIN
        ^";
  style roman;
  print "^
        Linking of commands by the use of punctuation and words like ";
  style bold;
  print "THEN";
  style roman;
  print " and ";
  style bold;
  print "AND";
  style roman;
  print " is also possible. For instance:^";
  style bold;
  print "^      GET THE SLINT RECORD FROM THE SHELF AND THEN PUT IT ON THE
        TURNTABLE
        ^      OPEN THE CAR DOOR. GET IN THE CAR. START THE CAR
        ^      REMOVE THE LOOSE TOOTH THEN THROW IT IN THE BIN
        ^      EXAMINE THE FILING CABINET. OPEN THE DRAWER. LOOK INSIDE THE
        DRAWER THEN TAKE EVERYTHING FROM IT
        ^";
  style roman;
  print "^
        Most players tend to type their commands in the most terse form
        acceptable. This includes the use of abbreviations (particularly in
        substituting the letter ";
  style bold;
  print "X";
  style roman;
  print " for ";
  style bold;
  print "EXAMINE";
  style roman;
  print " or ";
  style bold;
  print "L";
  style roman;
  print " for ";
  style bold;
  print "LOOK";
  style roman;
  print "), omission of the word ";
  style bold;
  print " THE ";
  style roman;
  print ", and use of ";
  style bold;
  print "ALL";
  style roman;
  print " rather than ";
  style bold;
  print "EVERYTHING";
  style roman;
  print ". So
        ^";
  style bold;
  print "^      X CABINET. OPEN DRAWER. L INSIDE IT THEN GET ALL FROM IT.
        ^";
  style roman;
  print "^
        would suffice just as well as the last command in the above list.
        ^^
        A verb which first-time players often try (with no success) is ";
  style bold;
  print "USE";
  style roman;
  print ". This is generally omitted from a game's vocabulary as it could make
        certain puzzles too easy. For instance, to get through a locked door
        the player might be required to smash a glass panel in it (using a
        hard object) then reach through and open a catch on the other side.
        Just typing ";
  style bold;
  print "USE LARGE KEY TO OPEN DOOR";
  style roman;
  print " might carry out all these actions and solve the problem when all the
        player wanted to do was try unlocking the door.
        ^";
];

[  OtherPeople;
  print "~Revenge~ allows you to interact with all the other characters you
        meet. Conversations are conducted with use of commands such as
        ^";
  style bold;
  print "^      SUSAN, HELLO
        ^      ASK KEITH ABOUT THE TEST MATCH
        ^      VAUGHAN, TELL ME ABOUT ELIZABETH TAYLOR
        ^";
  style roman;
  print "^
        You can try ordering others about with input along the lines of
        ^";
  style bold;
  print "^      ERROL, DRINK THE VODKA
        ^      PENGUIN, GO NORTH
        ^      UNCLE DAVE, CLIMB THE LADDER AND RELEASE THE BATS
        ^";
  style roman;
  print "^
        Just don't expect everyone to be quite so helpful as you yourself
        might be. There will arise times when actions do indeed speak louder
        than words, so you might want to
        ^";
  style bold;
  print "^      KISS STEPHANIE
        ^      SEARCH THE SUSPECT
        ^      HIT DEREK WITH THE PLANK OF WOOD
        ^      SHOW THE LAGER TO GAZZA.
        ^";
  style roman;
  print "^
        You may ask the game questions such as
        ^";
  style bold;
  print "^      WHO IS HARRY BURNS
        ^      WHAT IS RAMA.
        ^";
  style roman;
];

[  SpecialCommands;
  print "At times, you may want to know what you are carrying. For some
        reason, the command to find this out is ";
  style bold;
  print "INVENTORY";
  style roman;
  print "; usually abbreviated to";
  style bold;
  print " I";
  style roman;
  print ". This command has been extended to allow ";
  style bold;
  print "INVENTORY TALL";
  style roman;
  print " and ";
  style bold;
  print "INVENTORY WIDE";
  style roman;
  print ". Choose the one you like best. Other useful commands include ";
  style bold;
  print "WAIT";
  style roman;
  print " (unfortunately abbreviated to";
  style bold;
  print " Z";
  style roman;
  print ".
        ^^
        Before attempting something particularly dangerous, or when you just
        want a break, you can ";
  style bold;
  print "SAVE";
  style roman;
  print " your game. To continue at a later date, simply type ";
  style bold;
  print "RESTORE";
  style roman;
  print ". It is also possible to ";
  style bold;
  print "VERIFY";
  style roman;
  print " the story file to make sure it is intact. When you have had enough,
        type ";
  style bold;
  print "QUIT";
  style roman;
  print " to end the game or ";
  style bold;
  print "RESTART";
  style roman;
  print " to begin again.
        ^^
        Advanced Inform story files such as this one allow the player to type
        ";
  style bold;
  print "PLACES";
  style roman;
  print ", for a list of all the locations visited, and ";
  style bold;
  print "OBJECTS";
  style roman;
  print " for a similar list of all the things you have handled, and where you
        last saw them. From time to time, boxes containing quotations or
        epigrams will pop up. These are intended purely for the amusement of
        the player (although none of the ones in this game are really very
        amusing) and do not provide any information necessary in solving the
        game. You may switch them on or off with the commands ";
  style bold;
  print "QUOTES ON";
  style roman;
  print " and ";
  style bold;
  print "QUOTES OFF";
  style roman;
  print ". It is possible for your interpreter to keep a transcript of the
        game as you play, perhaps sending it to a printer or disk file. The
        commands ";
  style bold;
  print "SCRIPT ON";
  style roman;
  print " and ";
  style bold;
  print "SCRIPT OFF";
  style roman;
  print " control this feature.
        ^^
        When you first visit a room you will be given a long description of
        it. Upon returning, you will ordinarily be presented with only its
        name. Entering ";
  style bold;
  print "VERBOSE";
  style roman;
  print " will change this so long descriptions are always given, whereas
        typing ";
  style bold;
  print "SHORT";
  style roman;
  print " will always print just the room's name. ";
  style bold;
  print "NORMAL";
  style roman;
  print " returns you to the default state.
        ^^
        None of these special commands (except ";
  style bold;
  print "INVENTORY";
  style roman;
  print " and ";
  style bold;
  print "WAIT";
  style roman;
  print ") will cause time to pass in ~Revenge~.
        ^";
];

[ CreditsThanksSub;
  "Thanks to: Graham Nelson for Inform; Gareth Rees, Tjorbin Andersson, Sam
  Hulick, Christopher E. Forman and others for postings on Usenet; Volker
  Blasius for the I-F archive; Stefan Jokisch and David Kinder for Frotz.";
];

[ CreditsTechSub;
  "~Revenge~ was written with Inform 6. At some point every version, from
  6.0 to 6.14 was used. Similarly, all the 6/x libraries have been in here
  somewhere. My main computer is an Amiga A1200, with GVP accelerator and
  10Mb RAM. I use CygnusEd Professional on the Amiga.";
];

[ CreditsInformSub;
  "~Revenge~ is written in ~Inform~, a freely distributable language which
  converts a (relatively) C-like source code into a format which is to all
  intents and purposes identical to that produced by the ZIL language used by
  Infocom in the 1980s.
  ^^
  ~Inform~ was written by Graham Nelson, and it is only to protect his
  reputation as an author of top quality games that I have refrained from
  naming him as co-author of ~Revenge~.
  ^^
  For anyone wishing to write their own adventures, I cannot recommend
  ~Inform~ highly enough. It is simple to learn, produces professional quality
  results and is absolutely free.
  ^^
  The author of the language says he has no objection to people making money
  from games written in ~Inform~, but given that he has put so much work into
  the libraries, compiler and documentation then distributed them for free, I
  consider it a bit of a cheek for anyone to ask money for a game written
  using them.";
];

[ CreditsAuthorSub;
  print "Currently I am 24, unemployed and live near Sheffield.";
];

[ MainInfo;
  switch(menu_item) {
    1:
      item_name = "What Is This?";
      item_width = 6;
      rfalse;
    2:
      item_name = "How To Play";
      item_width = 6;
      rfalse;
    3:
      item_name = "License";
      item_width = 3;
      rfalse;
    4:
      item_name = "Credits";
      item_width = 4;
      rfalse;
    0:
      item_name = "Revenge";
      item_width = 4;
      return 4;
    default:
      "* ERROR *";
  }
];

[ MainMenu;
  switch(menu_item) {
    0:
      item_name = "Revenge";
      item_width = 4;
      return 4;
    1:
      HelpWhatSub();
      rtrue;
    2:
      HowToPlaySub();
      return 2;
    3:
      HelpLicenseSub();
      rtrue;
    4:
      CreditsSub();
      return 2;
    default:
      "* ERROR *";
  }
];


[ MenuSub;
  DoMenu("There is information provided on the following:^
         ^     What Is This?
         ^     How To Play
         ^     Licensing Information
         ^     Credits",
         MainInfo, MainMenu);
];

[ HowToInfo;
  switch(menu_item) {
    0:
      item_name = "How To Play ~Revenge~";
      item_width = 10;
      return 4;
    1:
      item_name = "Moving Around In ~Revenge~";
      item_width = 13;
      rfalse;
    2:
      item_name = "Manipulating Objects";
      item_width = 10;
      rfalse;
    3:
      item_name = "Interacting with other people";
      item_width = 14;
      rfalse;
    4:
      item_name = "Special Commands";
      item_width = 8;
      rfalse;
    default: "* ERROR *";
  }
];

[ HowToMenu;
  switch(menu_item) {
    0:
      item_name = "Commands";
      item_width = 4;
      return 4;
    1:
      MovingAround();
      rtrue;
    2:
      ManipulatingObjects();
      rtrue;
    3:
      OtherPeople();
      rtrue;
    4:
      SpecialCommands();
      rtrue;
    default:
      "* ERROR *";
  }
];


[ CreditsSub;
  DoMenu("Please select one of the following:^
         ^     Acknowledgements and thanks
         ^     Technical
         ^     About Inform
         ^     About the Author",
         CreditsInfo, CreditsMenu);
];

[ CreditsInfo;
  switch(menu_item) {
    0:
      item_name = "Credits";
      item_width = 4;
      return 4;
    1:
      item_name = "Acknowledgements and Thanks";
      item_width = 14;
      rfalse;
    2:
      item_name = "Technical";
      item_width = 5;
      rfalse;
    3:
      item_name = "About Inform";
      item_width = 7;
      rfalse;
    4:
      item_name = "About The Author";
      item_width = 8;
      rfalse;
    default:
    "* ERROR *";
  }
];

[ CreditsMenu;
  switch(menu_item) {
    0:
      item_name = "Credits";
      item_width = 4;
      return 4;
    1:
      CreditsThanksSub();
      rtrue;
    2:
      CreditsTechSub();
      rtrue;
    3:
      CreditsInformSub();
      rtrue;
    4:
      CreditsAuthorSub();
      rtrue;
    default:
      "* ERROR *";
  }
];

![ amusing;
! print "Have you tried...  Eating the silver foil tray?  Entering the bin?
! Rubbing the bottle of Ribena?  Eating the banger?  Insulting Simone?  Asking
! the policeman about his partner?  Or about music?"; !];
