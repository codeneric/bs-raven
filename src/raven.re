type installable;

type configuration;

[@bs.send] external install : installable => unit = "";

[@bs.obj] external makeConfig : (~release: string=?, unit) => configuration = "";

module Internal = {
  type dns = string;
  [@bs.module "raven-js"] external configOnylDns : dns => installable = "config";
  [@bs.module "raven-js"] external config : (dns, configuration) => installable = "config";
};

let config = (dns: string, ~config: option(configuration)=?, ()) =>
  switch config {
  | None => Internal.configOnylDns(dns)
  | Some(c) => Internal.config(dns, c)
  };

[@bs.module "raven-js"] external captureException : Js.Exn.t => unit = "";

[@bs.module "raven-js"] external captureMessage : string => unit = "";