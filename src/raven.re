type static;

type options;

type transportOptions;

type autoBreadcrumbOptions;

type instrumentationOptions;

type userContext;

type breadcrumb;

[@bs.send] external install : static => unit = "";

[@bs.obj]
external makeConfig :
  (
    ~release: string=?,
    ~level: [@bs.string] [ | `info | `critical | `error | `warning | `debug]=?,
    ~logger: string=?,
    ~environment: string=?,
    ~serverName: string=?,
    ~ignoreErrors: array(string)=?,
    ~ignoreUrls: array(string)=?,
    ~whitelistUrls: array(string)=?,
    ~includePaths: array(string)=?,
    ~tags: Js.Dict.t(string)=?,
    ~stacktrace: Js.boolean=?,
    ~extra: Js.t('a)=?,
    ~fingerprint: array(string)=?,
    ~dataCallback: 'a => 'b=?,
    ~shouldSendCallback: 'a => Js.boolean=?,
    ~maxMessageLength: int=?,
    ~maxUrlLength: int=?,
    ~transport: transportOptions => unit=?,
    ~headers: Js.Dict.t(string)=?,
    ~fetchParameters: Js.Dict.t(string)=?,
    ~allowSecretKey: Js.boolean=?,
    ~instrument: instrumentationOptions=?,
    ~autoBreadcrumbs: autoBreadcrumbOptions=?,
    ~maxBreadcrumbs: int=?,
    ~breadcrumbCallback: 'a => 'b=?,
    ~sampleRate: float=?,
    ~allowDuplicates: Js.boolean=?,
    unit
  ) =>
  options =
  "";

[@bs.obj]
external makeUserContext :
  (~id: string=?, ~username: string=?, ~email: string=?, unit) => userContext =
  "";

[@bs.obj]
external makeBreadcrumb :
  (
    ~message: string=?,
    ~category: string=?,
    ~level: [@bs.string] [ | `info | `critical | `error | `warning | `debug]=?,
    ~_type: [@bs.string] [ | `navigation | `http]=?,
    unit
  ) =>
  breadcrumb =
  "";

module Internal = {
  type dsn = string;
  [@bs.module "raven-js"] external configOnylDns : dsn => static = "config";
  [@bs.module "raven-js"] external config : (dsn, options) => static = "config";
};

let config = (~dsn: string, ~config: option(options)=?, ()) =>
  switch config {
  | None => Internal.configOnylDns(dsn)
  | Some(c) => Internal.config(dsn, c)
  };

[@bs.module "raven-js"] external captureException : Js.Exn.t => static = "";

[@bs.module "raven-js"] external captureExceptionWithOptions : (Js.Exn.t, options) => static = "";

[@bs.module "raven-js"] external captureMessage : string => static = "";

[@bs.module "raven-js"] external captureMessageWithOptions : (string, options) => static = "";

[@bs.module "raven-js"] external captureBreadcrumb : breadcrumb => static = "";

[@bs.module "raven-js"] external setUserContext : userContext => static = "";

[@bs.module "raven-js"] external setExtraContext : Js.t('a) => static = "";

[@bs.module "raven-js"] external setTagsContext : Js.t('a) => static = "";

/* When passing undefined to setUserContext raven-js implicitly clears the context */
[@bs.module "raven-js"] external clearUserContext : unit => static = "setUserContext";