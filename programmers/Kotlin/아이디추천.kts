{\rtf1\ansi\ansicpg949\cocoartf2578
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Italic;}
{\colortbl;\red255\green255\blue255;\red184\green93\blue213;\red30\green33\blue39;\red155\green162\blue177;
\red222\green180\blue104;\red81\green158\blue235;\red197\green136\blue84;\red136\green185\blue102;\red214\green85\blue98;
}
{\*\expandedcolortbl;;\csgenericrgb\c72157\c36471\c83529;\csgenericrgb\c11765\c12941\c15294;\csgenericrgb\c60784\c63529\c69412;
\csgenericrgb\c87059\c70588\c40784;\csgenericrgb\c31765\c61961\c92157;\csgenericrgb\c77255\c53333\c32941;\csgenericrgb\c53333\c72549\c40000;\csgenericrgb\c83922\c33333\c38431;
}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 import \cf4 java.lang.\cf5 StringBuilder\
\
\cf2 class \cf5 Solution \cf4 \{\
    \cf2 private fun \cf6 check\cf4 (\cf7 ch\cf4 : \cf5 Char\cf4 ): \cf5 Boolean\cf4 \{\
        \cf2 return \cf7 ch\cf4 .\cf6 isLetterOrDigit\cf4 () || \cf7 ch \cf4 == \cf8 '-' \cf4 || \cf7 ch \cf4 == \cf8 '_' \cf4 || \cf7 ch \cf4 == \cf8 '.'\
    \cf4 \}\
\
    \cf2 fun \cf6 solution\cf4 (\cf7 new_id\cf4 : \cf5 String\cf4 ): \cf5 String \cf4 \{\
        \cf2 var 
\f1\i \cf4 answer 
\f0\i0 = \cf6 StringBuilder\cf4 (\cf8 ""\cf4 )\
        \cf2 var 
\f1\i \cf4 flag 
\f0\i0 = \cf2 false\
        for\cf4 (ch \cf2 in \cf7 new_id\cf4 ) \{\
            \cf2 if \cf4 (!\cf6 check\cf4 (ch)) \cf2 continue\cf4 ;\
            
\f1\i flag 
\f0\i0 = \cf2 if \cf4 (ch == \cf8 '.'\cf4 ) \{\
                \cf2 if \cf4 (
\f1\i flag
\f0\i0 ) \cf2 continue\
                true\
            \cf4 \} \cf2 else \cf4 \{\
                \cf2 false\
            \cf4 \}\
            
\f1\i answer
\f0\i0 .\cf6 append\cf4 (ch.\cf6 toLowerCase\cf4 ())\
        \}\
\
        \cf2 if\cf4 (
\f1\i answer
\f0\i0 .\cf6 isNotEmpty\cf4 ())\
            \cf2 if\cf4 (
\f1\i answer
\f0\i0 [\cf7 0\cf4 ] == \cf8 '.'\cf4 )\
                
\f1\i answer
\f0\i0 .\cf6 deleteCharAt\cf4 (\cf7 0\cf4 )\
\
        \cf2 if\cf4 (
\f1\i answer
\f0\i0 .\cf6 isNotEmpty\cf4 ())\
            \cf2 if\cf4 (
\f1\i answer
\f0\i0 [
\f1\i answer
\f0\i0 .\cf9 length \cf4 - \cf7 1\cf4 ] == \cf8 '.'\cf4 )\
                
\f1\i answer
\f0\i0 .\cf6 deleteCharAt\cf4 (
\f1\i answer
\f0\i0 .\cf9 length \cf4 - \cf7 1\cf4 )\
\
        \cf2 if\cf4 (
\f1\i answer
\f0\i0 .\cf6 isEmpty\cf4 ())  
\f1\i answer
\f0\i0 .\cf6 append\cf4 (\cf8 "a"\cf4 )\
\
        \cf2 if\cf4 (
\f1\i answer
\f0\i0 .\cf9 length \cf4 > \cf7 15\cf4 ) \{\
            
\f1\i answer 
\f0\i0 = \cf6 StringBuilder\cf4 (
\f1\i answer
\f0\i0 .\cf6 substring\cf4 (\cf7 0\cf4 ..\cf7 14\cf4 ))\
            \cf2 if\cf4 (
\f1\i answer
\f0\i0 [
\f1\i answer
\f0\i0 .\cf9 length \cf4 - \cf7 1\cf4 ] == \cf8 '.'\cf4 )\
                
\f1\i answer
\f0\i0 .\cf6 deleteCharAt\cf4 (
\f1\i answer
\f0\i0 .\cf9 length \cf4 - \cf7 1\cf4 )\
        \}\
\
        \cf2 if\cf4 (
\f1\i answer
\f0\i0 .\cf9 length \cf4 < \cf7 3\cf4 )\{\
            \cf2 val \cf4 temp = 
\f1\i answer
\f0\i0 [
\f1\i answer
\f0\i0 .\cf9 length\cf4 -\cf7 1\cf4 ]\
            \cf2 while\cf4 (
\f1\i answer
\f0\i0 .\cf9 length \cf4 < \cf7 3\cf4 )\{\
                
\f1\i answer
\f0\i0 .\cf6 append\cf4 (temp)\
            \}\
        \}\
\
        \cf2 return 
\f1\i \cf4 answer
\f0\i0 .\cf6 toString\cf4 ()\
    \}\
\}\
}