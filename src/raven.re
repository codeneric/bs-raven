type static;

type options;

type transportOptions;

type autoBreadcrumbOptions;

type instrumentationOptions;

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

[@bs.module "raven-js"] external captureException : Js.Exn.t => unit = "";

[@bs.module "raven-js"] external captureExceptionWithOptions : (Js.Exn.t, options) => unit = "";

[@bs.module "raven-js"] external captureMessage : string => unit = "";

[@bs.module "raven-js"] external captureMessageWithOptions : (string, options) => unit = "";