!---------------------------------------------------------------------------
! Adname - an Inform library by Andrew Clover, release 3
!          Compatible with Inform 5.5 and later. Freely usable.
!
! This Inform library provides a new property 'adname', which holds words
! the player should be able to include the typed name of an object, but do
! not on their own imply that the object has been referred to. (For example,
! the word 'toilet' in the object 'roll of toilet paper'.)
!
! Include "Adname"; just after VerbLib.
!---------------------------------------------------------------------------

! This library provides a solution similar to the answer to example 60 in
! the Inform Designers' Manual, except that groups of identical objects are
! handled correctly. There is also (for flexibility) no requirement that
! adnames come before names - so you can have a 'ring of power' ('power' and
! 'of' being adnames) as well as a 'power ring'.
!
! Note that adnames, unlike names, must be quoted in single quotes. Now that
! names can be quoted like this too, it is recommended you use single quotes
! for names.
!
! Example: object coffin_stand "coffin stand"
!          class adnc
!          with
!            name 'stand' 'coffin-stand',
!            adname 'coffin' 'wooden' 'smart',
!            description
!              "You can refer to this smart wooden coffin stand as 'coffin
!              stand', but 'coffin' alone will mean the coffin itself.",
!          has
!            static;
!---------------------------------------------------------------------------

! Changes from release 1: one can now use the adnc class without having to
! give the object the adname property. This means you can base other classes
! on adnc without objects of these classes having to have adnames.

property adname;

class adnc
with
  adname 0,
  parse_name [;
    return AdnameParser(self);
  ];

[ AdnameParser adobj w n i j a b succ fail;
  if (parser_action==##TheSame) {
    w= parser_one.&adname;
    n= (parser_one.#adname)/2;
    i= parser_two.&adname;
    j= (parser_two.#adname)/2;
    if ((w-->0)==0 || (i-->0)==0) {
      if ((w-->0)==(i-->0))
        return -1;
      else
        return -2;
    }
    for (a= 0: a<n: a++) {
      fail= 1;
      for (b= 0: b<j: b++)
        if ((w-->a)==(i-->b))
          fail= 0;
      if (fail==1)
        return -2;
    }
    for (a= 0: a<j: a++) {
      fail= 1;
        for (b= 0: b<n: b++)
          if ((w-->b)==(i-->a))
            fail= 0;
      if (fail==1)
        return -2;
    }
    return 0;                             ! This bit adapted from the parser
                                          ! - check all words in adname of
                                          ! parser_one to see if they occur
                                          ! in adname of parser_two, then
                                          ! vice-versa. If either case is
                                          ! false, we say the objects are not
                                          ! the same (the player may type a
                                          ! word that distiguishes then); if
                                          ! both are true, we give the parser
                                          ! a crack at seeing if they're
                                          ! different (by looking at the name
                                          ! property).
  }
  else {
    if (((adobj.&adname)-->0)==0)
      return -1;
    n= 0;
    succ= 0;
    fail= 0;
    while (fail==0) {
      fail= 1;
      w= NextWord();
      for (i= 0: i<(adobj.#adname)/2: i++) {
        if (w==adobj.&adname-->i)
          fail= 0;
      }
      for (i= 0: i<(adobj.#name)/2: i++) {
        if (w==adobj.&name-->i) {
          fail= 0;
          succ= 1;
        }
      }
      n++;
    }
    if (succ==1)
      return n-1;
    else
      return 0;                           ! This is the bit of code executed
                                          ! normally (when the parser isn't
                                          ! trying to resolve identical
                                          ! objects). We just check that
                                          ! every word typed is in the adname
                                          ! or name property, and say that
                                          ! the phrase matches the object if
                                          ! any words are in the name.
  }
];