//
//  AppDelegate.h
//
//  Created by Patrick Wardle on 2/6/15.
//  Copyright (c) 2015 Objective-See, LLC. All rights reserved.
//

#import "Binary.h"
#import <Cocoa/Cocoa.h>

@class PrefsWindowController;

@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate, NSTableViewDataSource, NSTableViewDelegate>
{
   

}

//array to hold binary objects that are in array
@property (nonatomic, retain)NSMutableArray *tableContents;

//index of 'Vulnerable Applications' header row
@property NSUInteger vulnerableAppHeaderIndex;

@property (assign) IBOutlet NSWindow *window;

//version string
@property (weak) IBOutlet NSTextField *versionString;


//main table view
@property (weak) IBOutlet NSTableView *resultsTableView;


@property (weak) IBOutlet NSButton *scanButton;
@property (weak) IBOutlet NSTextField *scanButtonLabel;
-(IBAction)scanButtonHandler:(id)sender;

//spinner
@property (weak) IBOutlet NSProgressIndicator *progressIndicator;
@property (weak) IBOutlet NSTextField *statusText;

//button handler for 'weak hijack detection'
//-(IBAction)hijackDetectionOptions:(id)sender;

//gear (show prefs) button
@property (weak) IBOutlet NSButton *showPreferences;

//button handler for when settings icon (gear) is clicked
-(IBAction)showPreferences:(id)sender;

//settings window controller
@property (nonatomic, retain) PrefsWindowController* prefsWindowController;

//non-UI thread that performs actual scan
@property (nonatomic, strong) NSThread *scannerThread;

//number of hijacked binaries
@property NSUInteger hijackCount;

//number of vulnerable binaries
@property NSUInteger vulnerableCount;

/* METHODS */

//display error alert
-(void)showUnsupportedAlert;

//callback method
// ->adds a hijacked/vulnerable binary to the table
-(void)addToTable:(Binary*)binary;

//shows alert stating that that scan is complete (w/ stats)
-(void)displayScanStats;

//handler for 'about' menu item and logo (bottom)
// ->go to objective-see's website
-(IBAction)about:(id)sender;

@end
