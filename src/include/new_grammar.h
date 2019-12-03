! Additions and replacements to the standard Inform Grammar
! Requires New_Verblib.inf

#IFDEF DEBUG;
  Message "Compiling new_grammar";
#ENDIF;

Verb 'bend' 'fold'
  * noun -> Bend;

Verb 'burst' 'pop' 'deflate' 'slash' 'pierce' 'puncture'
  * noun -> Burst
  * noun 'with' held -> Burst;

Verb 'catch'
  * noun -> Catch;

Verb 'crush'
  * noun -> Crush
  * noun 'with' held -> Crush;

!Verb 'dial' 'ring' 'phone' 'call' 'telephone'
! * PhoneNumber -> DialPhone
! * PhoneNumber 'on' noun -> DialPhone;

Verb 'fish'
  * -> GoFishin;

Verb "help" "menu" "info" "information" "instructions"
  * -> Menu;

Verb "diagnose"
  * -> Diagnose;

Verb "xyzzy" "plugh" "plover" "abracadabra" "shazam"
  * -> xyzzy
  * noun -> xyzzy;

Verb 'hide'
  * 'behind' noun -> Hide;

Verb 'kick' 'shoe' 'boot' 'punt' 'pass'
  * noun -> Knock
  * noun 'over' noun -> KickOver
  * noun 'through'/'thru' noun -> KickThrough
  * creature -> Attack
  * creature -> Attack
  * noun 'at'/'to' noun -> KickAt;

Verb 'ls'
  * -> Ls;

Verb 'make'
  * noun -> Make;

Verb 'plant' 'sow'
  * noun -> Plant
  * held 'in' noun -> Plant;

Verb 'point' 'aim'
  * noun 'at' noun -> Point;

Verb 'pour' 'tip' 'teem'
  * noun -> Pour
  * noun 'on'/'onto'/'in'/'into'/'over' noun -> Pour;

Verb 'shave'
  * -> Shave;

Verb 'shoot' 'ventilate'
  * noun 'with' held -> Shoot;

Verb 'start'
  * noun -> SwitchOn;

Verb 'stick'
  * held 'on'/'to' noun -> PutOn
  * held 'over' noun -> Cover
  * held 'through'/'thru' noun -> Pierce;

Verb 'stop'
  * noun -> SwitchOff;

Verb 'stroke' 'pat' 'pet'
  * noun -> Stroke;

Verb 'unplug' 'disconnect'
  * noun -> UnPlug;

Verb 'untie' 'unfasten'
  * noun -> Untie;

Verb 'water'
  * noun -> Water
  * noun 'with' held -> Water;

Extend 'attack'
  * noun 'with' held -> Attack;

Extend 'climb' last
  * 'on'/'onto' noun -> Climb
  * 'onto' noun -> Climb;

Extend 'consult' first
  * noun 'about'/'on' scope = TopicScope -> NewConsult;

Extend only 'cover' replace
  * noun 'with' held -> Cover;

Extend 'cut' replace
  * noun 'with' held -> Cut
  * 'down' noun 'with' held -> Cut
  * noun 'down' 'with' held -> Cut;

Extend 'dig' replace
  * -> Dig
  * 'in' noun 'with' held -> Dig
  * noun 'with' held -> Dig;

Extend 'fill'
  * noun 'with' noun -> FillWith;

Extend 'go' first
  * 'fishing' -> GoFishin;

Extend 'get' last
  * 'onto' noun -> Climb;

Extend 'look' first
  * -> Look
  * 'up' scope=TopicScope 'in' noun -> NewConsultR;

Extend 'look' last
  * 'up' ConTopic 'in' noun -> Consult
  * 'behind' noun -> LBehind
  * 'over' noun -> LookOver;

Extend 'peel'
  * noun 'off' -> Take
  * 'off' noun -> Take
  * noun 'off' held -> Take;

Extend 'pull' last
  * noun 'with' held -> PullWith;

Extend 'push'
  * noun 'into' noun -> PushInto
  * held 'through'/'thru' noun -> Pierce;

Extend 'put'
  * held 'across' noun -> PutOn
  * held 'through'/'thru' noun -> Pierce;

Extend 'read' first
  * 'about' scope=TopicScope 'in' noun -> NewConsultR
  * scope=TopicScope 'in' noun -> NewConsultR;

Extend 'read' last
  * 'about' ConTopic 'in' noun -> Consult
  * ConTopic 'in' noun -> Consult;

Extend 'remove' last
  * noun 'from' noun -> Take;

Extend 'stand' replace
  * 'on' noun -> Climb;

Extend 'throw' last
  * held 'through'/'thru'/'out' noun -> ThrowThrough;

Extend 'tie' replace
  * noun 'round'/'around' noun -> TieRound
  * noun 'to' noun -> TieTo;

Extend 'touch'
  * 'under'/'underneath' noun -> FeelUnder;

Extend 'turn' last
  * noun 'with' held -> Unscrew;

!Extend 'wait'
! * 'until'/'til'/'till'/'for' parsetime -> WaitUntil
! * number 'minute'/'minutes'/'times' -> WaitMoves
! * number 'hour'/'hours' -> WaitHours
! * number -> WaitMoves
! * parsetime -> WaitUntil;

Verb 'knock' 'bang' 'tap'
  * 'on' noun -> Knock;

Extend 'look' last
  * 'through'/'thru' noun -> Search
  * noun -> LookDir;
