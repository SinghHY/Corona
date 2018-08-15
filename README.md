# Corona

This program written for SOURCE and HSID board of IONICAXX to                                    //
//              control the HV and Temperature of HSID and Source                                                //
//              MehrdadT@ionics.ca         Date : Aug 12th, 2008                                          //   
//              Version : 2.0 based on dsPIC33                                                    //   
//              comment: this version has a PID control parameter to control temperature with seperate           //
//                       thermocouple                                                                            //
//              latest update for Source May12 was regarding immidiate heater shut down after zero set point     // 
//              in this version I added an option to current control of Crona HV                                 //
//              latest update for HV+ and HV- seperate setting                                                   // 
//              last  update for crona current control july 9th                                                  // 
//              last update for corona control hv+ and hv- july 15th                                             //
//              last updat for corona control hangout problem Nov11th                                            // 
//              Modified probeID logic for HV reset April 6th,2010                                               //                  
//              Modified SPI the same as rest Sep23,2010 also vesrion readable from ionsniffer                   // 
//              Modified for achieve fast switching @ April 28th 2011                                            //                   
//              Modified for acheive 2 APCI probe at the same time @ Oct 2012                                    //  
//              Modified to work with new hardware (current control) @June 2013              