//
//  ZoomSDKNetworkService.h
//  ZoomSDK
//
//  Created by TOTTI on 2/28/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct ZoomSDKProxySettings{
    NSString*     _proxy;
    BOOL          _autoDetct;
}ZoomSDKProxySettings;

@interface ZoomSDKProxySettingHelper : NSObject
{
    NSString*   _proxyHost;
    int         _proxyPort;
    NSString*   _proxyDescription;
}
/**
 * @brief Get proxy host.
 * @return The proxy host.
 */
- (NSString*)getProxyHost;
/**
 * @brief Get proxy port.
 * @return The proxy port.						  
 */
- (int)getProxyPort;
/**
 * @brief Get description of proxy.
 * @return The proxy description.
 */
- (NSString*)getProxyDescription;
/**
 * @brief Authentication of proxy.
 * @param userName Input username for authentication.
 * @param password Input password for authentication.
 */
- (void)proxyAuth:(NSString*)userName password:(NSString*)password;
/**
 * @param Cancel authentication of proxy.
 */
- (void)cancel;
@end

@interface ZoomSDKSSLVerificationHelper :NSObject
{
    NSString* _certIssueTo;
    NSString* _certIssueBy;
    NSString* _certSerialNum;
    NSString* _certFingerprint;
}
/**
 * @brief The certificate is issued to whom.
 * @return The user to whom the certificate is issued.
 */
- (NSString*)getCertIssueTo;
/**
 * @brief The certificate is issued by whom.
 * @return The user by whom the certificate is issued.									  
 */
- (NSString*)getCertIssueBy;
/**
 * @brief Get serial number of certificate.
 * @return The serial number of the certificate.
 */
- (NSString*)getCertSerialNum;
/**
 * @param Get fingerprint of certificate.
 * @return The fingerprint of the certificate.
 */
- (NSString*)getCertFingerprint;
/**
 * @brief Trust the certificate.
 */
- (void)trust;
/**
 * @brief Cancel the certificate.
 */
- (void)cancel;

@end

@protocol ZoomSDKNetworkSeviceDelegate <NSObject>
/**
 * @brief The callback will be triggered if the proxy requests to input the username and password.
 * @param proxyHelper A ZoomSDKProxySettingHelper object containing proxy information. 
 */
- (void)onProxySettingNotification:(ZoomSDKProxySettingHelper*)proxyHelper;

/**
 * @brief The callback will be triggered when the SSL needs to be verified.
 * @param sslHelper A ZoomSDKSSLVerificationHelper object contains SSL verification information. 
 *
 */
- (void)onSSLCertVerifyNotification:(ZoomSDKSSLVerificationHelper*)sslHelper;

@end

@interface ZoomSDKNetworkService : NSObject
{
    id<ZoomSDKNetworkSeviceDelegate>  _delegate;
}
@property(nonatomic, retain) id<ZoomSDKNetworkSeviceDelegate> delegate;

/**
 * @brief Configure the proxy for Zoom SDK.
 * @param ZoomSDKProxySettings A struct object containing proxy information.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)ConfigureProxy:(ZoomSDKProxySettings)settings;
@end
