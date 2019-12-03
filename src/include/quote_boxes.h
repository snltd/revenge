Array box_printed->24;

[ print_box i;
  if (box_printed->i == 1) {
    rtrue;
  }

  box_printed->i = 1;

  switch(i) {
    1:
      box "Been a creep ever since you met him"
          "It's time for revenge, we're really gonna get him"
          " -- Bis, ~Kill Yr Boyfriend~";

    2:
      box "Refinishing floors is nonsense. Floors are"
          "either finished or they aren't. If you can see"
          "into the basement, the floor isn't finished."
          !  examine kitchen floor
          ""
          " -- P.J. O'Rourke, ~The Bachelor Home Companion~";

    3:
      box "The French live to eat,"
          "the English eat to die."
          ""
          " -- Martin Amis, ~London Fields~";
          !  examine food

    4:
      box "Revenge, instant satisfaction,"
          "Sweet success for the working class."
          ""
          " -- Archers of Loaf, ~Revenge~";

    5:
      box "Baby"
          "I've been"
          "Breaking glass in your room again."
          ""
          " -- David Bowie, ~Breaking Glass~";

    6:
      box "Should you get a gun and"
          "Go and get revenge?"
          ""
          " -- Sonic Youth, ~100%~";
          !  remove gun from box

    7:
      box "Art is a science having more than seven variables."
          "And hi-fi is the convenient tag we use when we"
          "mean the art and science of hi-fidelity!"
          ""
          " -- Stereolab ~Jenny Ondioline~ sleevenotes";

    8:
      box "When you assume an attitude of suspicion,"
          "you overlook no clue."
          ""
          " -- Umberto Eco, ~Foucault's Pendulum~";

    9:
      box "Don't stand when you can sit,"
          "And don't sit when you can lie down"
          ""
          " -- The Author's motto"; ! sit on setee

    10:
      rtrue;

    11:
      box "Michael Jackson really sucks. He"
          "just dances around with monkeys"
          ""
          " -- Thurston Moore";  ! ask Donna about music

    12:
      box "Steve Bull's library burned down - both his"
          "books were lost, which is a pity because"
          "he'd only coloured one of them in."
          ""
          " -- a ~joke~ by Bull's former headmaster at"
          "    his school's speech day.";

    13:
      box "Sex is too wonderful to be shared"
          "with anybody else."
          ""
          " -- Philip Larkin";

    14:
      box "Each ditty demonstrates a dextrously quixotic"
          "command of classic Anglo-romantico. Blyth Power"
          "are sub-Byronic Tarzans swinging on the vine of"
          "thread bare literate rock lineage with only the"
          "immense Betjemantic talent of Josef Porta as an"
          "anchor."
          ""
          " -- Paul Temple, lp review in Melody Maker";

    15:
      box "I hate children, that's why I get on with them."
          ""
          " -- Sir Jimmy Saville";

    16:
      box "I got so scared on space cake"
          "I had to be rescued by Jimmy White."
          ""
          " -- Tony Meo";

    17:
      box "A beautiful paint-job,"
          "Hoplessly marred."
          ""
          " -- Sonic Youth, ~In the Kingdom #19~";
          !  examine smashed car

    18:
      box "Jimmy Hill: Don't sit on the fence Terry,"
          "            what chance do you think Germany"
          "            has got of getting through?"
          "Terry Venables:"
          "            I think it's fifty - fifty";
          ! sit on fence

    19:
      box "If it's true you've been with another,"
          "Gonna put my head in the oven."
          "Turn it up all the way to eleven,"
          "Then I'll find myself up in heaven"
          ""
          " -- Slipstream, ~Up In Heaven~";
         ! Enter microwave

    20:
      box "They [Sheffield United] couldn't hit a"
          "cow's backside with a banjo."
          ""
          " -- Dave Bassett about his strikers";  !

    21:
      box "This is the advent of a new beginning"
          "of continued change."
          ""
          " -- Ronald Reagan";

    22:
      box "If there weren't such a thing as"
          "football, we'd all be frustrated"
          "footballers."
          ""
          " -- Mick Lyons";

    23:
      box "Verbosity leads to unclear,"
          "inarticulate things."
          ""
          " -- Dan Quayle";
          ! enter verbose mode
    }
];
