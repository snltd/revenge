!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! Weather.h - version 1.0
!
! (c) 1998 Robert Fisher
!
! Classes and routines to more easily build a house and garden
!
! This may be used in any way you like. It may work, it may not. I take no
! responsibility for any problems, frustrations or personal injuries this
! software causes.
!
! If you wish to use my "house.h" module, include it BEFORE this file and
! uncomment the line DEFINE HAVE_WEATHER in that file.
!
! Be sure to uncomment and move the additions to the Grammar found at the
! end of this file.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#IFDEF DEBUG;
	Message "Compiling module weather.h";
#ENDIF;

! Look to see if we are using my "house.h" module, and if not, declare the
! missing attributes and properties.

#IFNDEF HAVE_WEATHER;
	Attribute outside;		! Give all your outdoor locations this attribute

	Property underfoot 0;	! For that all important "examine floor
	Property overhead 0;	! And the even more important "look up.
#ENDIF;

[	Daytime;
	if (the_time >= sunrise && the_time < twilight)	{
    ! DAYLIGHT
		return 1;
  }
  else if (the_time >= Twilight && the_time < sunset) {
    ! TWILIGHT
		return 2;
  }
  else {
    ! NIGHT TIME
	  return 3;
  }
];

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! Some classes for scenery. These are more detailed versions of those in
! my "house.h" module.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class The_Sky
with number 1,
	parse_name
	[ w1;
		w1 = NextWord();

		if ((w1 == 'clouds' or 'sky' or 'air' or 'atmosphere' or 'weather')) {
			self.number=1;
			return 2;
		}

		if (w1 == 'ceiling' or 'roof') {
			self.number=2;
			return 2;
		}

		return 0;
  ],
  article "the",
  before [;
    LookUnder:
      "The whole world sprawls out under the sky. (Before you ask, I think
      you'll find space is above it.)";
    default:
      "A Babelesque concept.";
  ],
  has	scenery;

The_Sky sky "sky"
  with
  before [;
    Examine:
      switch(self.number) {
        1:
          switch(daytime()) {
            1:
              "The sky is a pale wintry blue. A few thin white clouds hang in
              the stillness.";
            2:
              "It is definitely going dark.";
            3:
              "The sky is as dark as it ever gets here. The light pollution is
              high, but you can still pick out a couple of constellations.";
          }
        2:
          "You're outside: there is no ceiling.";
      }
  ];

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! This code was written on a Commodore Amiga A4000/040
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
