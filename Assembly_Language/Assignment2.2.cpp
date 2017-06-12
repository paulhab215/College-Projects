#include <iostream>
using namespace std;

int a1[11],
    a2[11],
    a3[11];



int main()
{
             char reply;
             int used1,
                 used2,
                 used3,
                 remCount,
                 anchor;
             int* hopPtr1 = 0;
             int* hopPtr11 = 0;
             int* hopPtr2 = 0;
             int* hopPtr22 = 0;
             int* hopPtr222 = 0;
             int* hopPtr3 = 0;
             int* endPtr1 = 0;
             int* endPtr2 = 0;
             int* endPtr3 = 0;

                //do
begDW1://       {
                used1 = 0;
                hopPtr1 = a1;
                   //do
begDW2://          {
                   cout << "Enter integer #" << (used1 + 1) << ": ";
                   cin >> *hopPtr1;
                   ++used1;
                   ++hopPtr1;
                     //if (used1 == 11)
		             if (used1 != 11) goto else1;
begI1://             {
                        cout << "Max of 11 ints entered..." << endl;
                        reply = 'n';
//                   }
else1://             else
//                   {
                        cout << "Enter more ints? (n or N = no, others = yes) ";
                        cin >> reply;
endI1://             }
endDW2://          }
DWTest2:         //while (reply != 'n' && reply != 'N');
		         if (reply == 'n') goto xitDW2;
		         if (reply != 'N') goto begDW2;
xitDW2:
                 cout << "beginning a1: ";
                 endPtr1 = a1 + used1;
	             //for (hopPtr1 = a1; hopPtr1 < endPtr1; ++hopPtr1)
		         hopPtr1 = a1;
		         goto FTest1;
begF1://         {
                 //if (hopPtr1 == endPtr1 - 1)
		         if (hopPtr1 != endPtr1 - 1) goto else2;
begI2://         {
                    cout << *hopPtr1 << endl;
		            goto endI2;	
//               }
                 //else
else2://         {
                    cout << *hopPtr1 << ' ';
endI2://         }
		         ++hopPtr1;

FTest1:		     if (hopPtr1 < endPtr1) goto begF1;
endF1://         }

                 //for (hopPtr1 = a1, hopPtr2 = a2, used2 = 0; hopPtr1 < endPtr1; ++hopPtr1, ++hopPtr2, ++used2)
		         hopPtr1 = a1;
		         hopPtr2 = a2;
		         used2 = 0;
		         goto FTest2;
begF2://         {
                  *hopPtr2 = *hopPtr1;
//               }

                 endPtr2 = a2 + used2;
                 //for (hopPtr2 = a2; hopPtr2 < endPtr2; ++hopPtr2)
		         hopPtr2 = a2;
		         goto FTest3;
begF3://         {
                    anchor = *hopPtr2;
                    //for (hopPtr22 = hopPtr2 + 1; hopPtr22 < endPtr2; ++hopPtr22)
	                hopPtr22 = hopPtr2 + 1;
		            goto FTest4;
begF4://            {
                      //if (*hopPtr22 == anchor)
		              if (*hopPtr22 != anchor) goto endI3;
begI3://              {
                         //for (hopPtr222 = hopPtr22 + 1; hopPtr222 < endPtr2; ++hopPtr222)
                         hopPtr222 = hopPtr22 +1;
			             goto FTest5;
begF5://	 	         {
                            *(hopPtr222 - 1) = *hopPtr222;

			             ++hopPtr222;
FTest5:			         if (hopPtr222 < endPtr2) goto begF5;
endF5://		         }
endI3:
                         --used2;
                         --endPtr2;
                         --hopPtr22;
			             ++hopPtr22;

FTest4:		         if (hopPtr222 < endPtr2) goto begF4;
endF4://             }
		             ++hopPtr2;

FTest3:		         if (hopPtr2 < endPtr2) goto begF3;
endF3://           }

		            ++hopPtr1;
		            ++hopPtr2;
		            ++used2;

FTest2:		     if (hopPtr1 < endPtr1) goto begF2;  
endF2://         }

                 used3 = 0;
                 hopPtr3 = a3;
                 hopPtr1 = a1;
                
		      //while (hopPtr1 < endPtr1)
	          goto WTest1;
begW1://      {
                   *hopPtr3 = *hopPtr1;
                   ++used3;
                   ++hopPtr3;
                   anchor = *hopPtr1;
                   remCount = 0;
                   //for (hopPtr11 = hopPtr1 + 1; hopPtr11 < endPtr1; ++hopPtr11)
		           hopPtr11 = hopPtr1;
		           goto FTest6;
begF6://           {
                      //if (*hopPtr11 == anchor)
		              if (*hopPtr11 != anchor) goto else3;
begI4://              {
                         ++remCount;
		                 goto endI4;
                      //}
else3://              else
//                    {
                         *(hopPtr11 - remCount) = *hopPtr11;
//                    }
endI4:
		              ++hopPtr11;
FTest6:		        if (hopPtr11 < endPtr1) goto begF6;
endF6://            }

                    used1 -= remCount;
                    endPtr1 -= remCount;
                    ++hopPtr1;
WTest1:		    if (hopPtr1 < endPtr1) goto begW1;
endW1://        }

                cout << "processed a1: ";
                //for (hopPtr1 = a1; hopPtr1 < endPtr1; ++hopPtr1)
                hopPtr1 = a1;
		        goto FTest7;
begF7://        {
                  //if (hopPtr1 == endPtr1 - 1)
		          if (hopPtr1 != endPtr1 -1) goto else4;
begI5://          {
                      cout << *hopPtr1 << endl;
//                }
else4://          else
//                {
                      cout << *hopPtr1 << ' ';
endI5://          }
		          ++hopPtr1;

FTest7:		   if (hopPtr1 < endPtr1) goto begF7;
endF7://       }
               cout << "          a2: ";
               //for (hopPtr2 = a2; hopPtr2 < endPtr2; ++hopPtr2)
               hopPtr2 = a2;
		       goto FTest8;
begF8://       {
                   //if (hopPtr2 == endPtr2 - 1)
                   if (hopPtr2 != endPtr2 -1) goto else5;
begI6://           {
                      cout << *hopPtr2 << endl;
//                 }
else5://           else
//                 {
                      cout << *hopPtr2 << ' ';
endI6://           }
           	       ++hopPtr2;

FTest8:		   if (hopPtr2 < endPtr2) goto begF8;
endF8://       }

                cout << "          a3: ";
                endPtr3 = a3 + used3;
                
		        //for (hopPtr3 = a3; hopPtr3 < endPtr3; ++hopPtr3)
                hopPtr3 = a3;
		        goto FTest9;
begF9://	    {
                   //if (hopPtr3 == endPtr3 - 1)
                   if (hopPtr3 != endPtr3-1) goto else6;
begI7://	       {
                      cout << *hopPtr3 << endl;
//                 }
else6://           else
//                 {
                      cout << *hopPtr3 << ' ';
endI7://           }
		           ++hopPtr3;
		
FTest9:  	    if (hopPtr3 < endPtr3) goto begF9;
endF9://        }

                cout << "Do another case? (n or N = no, others = yes) ";
                cin >> reply;
endDW1://    }
             //while (reply != 'n' && reply != 'N');
	         if (reply == 'n') goto xitDW1;
	         if (reply != 'N') goto begDW1;

xitDW1:
             cout << "================================" << endl;
             cout << "bye..." << endl;
             cout << "================================" << endl;

             return 0;
}

