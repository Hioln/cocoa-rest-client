//
//  CRCSaveRequest.h
//  CocoaRestClient
//
//  Created by Adam Venturella on 7/10/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRCConstants.h"

@class MainWindowController;

enum {
    CRCContentTypeMultipart,
    CRCContentTypeFormEncoded,
    CRCContentTypeJson,
    CRCContentTypeXml,
    CRCContentTypeImage,
    CRCContentTypeUnknown
};
typedef NSInteger CRCContentType;

@interface CRCRequest : NSObject <NSCoding> {
	BOOL rawRequestInput;
	NSString * name;
	NSString * url;
	NSString * method;
	NSString * requestText;
	NSString * username;
	NSString * password;
	NSArray * headers;
	NSArray * files;
	NSArray * params;
    BOOL preemptiveBasicAuth;
}

@property BOOL rawRequestInput;
@property(nonatomic, copy) NSString * name;
@property(nonatomic, copy) NSString * url;
@property(nonatomic, copy) NSString * method;
@property(nonatomic, copy) NSString * requestText;
@property(nonatomic, copy) NSString * username;
@property(nonatomic, copy) NSString * password;
@property(nonatomic, copy) NSArray * headers;
@property(nonatomic, copy) NSArray * files;
@property(nonatomic, copy) NSArray * params;
@property BOOL preemptiveBasicAuth;

+ (CRCRequest *)requestWithWindow:(MainWindowController *)mainWindowController named:(NSString *)name;
- (CRCRequest *)overwriteContentsWith:(CRCRequest *)request;
- (NSString *) generateCurlCommand:(bool)followRedirects;
+ (CRCContentType) determineRequestContentType:(NSArray *)headers;

@end
